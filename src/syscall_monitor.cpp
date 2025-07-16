#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <dirent.h>
#include <unistd.h>
#include <vector>
#include "policy_loader.h"
#include "causal_logger.h"

// Helper: Check if a string is numeric (used to find PIDs)
bool is_numeric(const std::string& str) {
    return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

// Monitor /proc/<pid>/fd and /proc/<pid>/exe
bool check_process_syscalls(const std::string& pid) {
    std::string exe_link = "/proc/" + pid + "/exe";
    char buf[4096];
    ssize_t len = readlink(exe_link.c_str(), buf, sizeof(buf)-1);
    if (len > 0) {
        buf[len] = '\0';
        std::string path(buf);
        if (matches_policy("execve", path)) {
            log_event("DENY", "execve", path, "Policy block");
            kill(std::stoi(pid), SIGKILL);
            return true;
        }
    }
    return false;
}

bool start_syscall_monitor() {
    std::cout << "[NeuroRAN] Starting syscall monitor (proc scan mode)..." << std::endl;

    while (true) {
        DIR* proc = opendir("/proc");
        if (!proc) return false;

        dirent* entry;
        while ((entry = readdir(proc)) != nullptr) {
            std::string pid(entry->d_name);
            if (is_numeric(pid)) {
                check_process_syscalls(pid);
            }
        }
        closedir(proc);
        usleep(100000); // 100ms
    }
    return true;
}
