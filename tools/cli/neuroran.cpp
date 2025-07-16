#include <iostream>
#include <fstream>
#include <string>
#include "../include/policy_loader.h"
#include "../include/causal_logger.h"

void usage() {
    std::cout << "NeuroRAN CLI\n";
    std::cout << "Usage:\n";
    std::cout << "  --check <syscall> <path>     Test if a path would match any policy\n";
    std::cout << "  --log <action> <syscall> <target> <reason>   Log an event manually\n";
    std::cout << "  --tail                       Print last 10 events\n";
}

void tail_log() {
    std::ifstream file("neuroran_events.log");
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
        if (lines.size() > 10)
            lines.erase(lines.begin());
    }
    for (const auto& l : lines)
        std::cout << l << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        usage();
        return 1;
    }

    std::string cmd = argv[1];

    if (cmd == "--check" && argc == 4) {
        load_policies("/etc/neuroran/default-policy.yaml");
        bool match = matches_policy(argv[2], argv[3]);
        std::cout << (match ? "MATCHED\n" : "NO MATCH\n");
    } else if (cmd == "--log" && argc == 6) {
        log_event(argv[2], argv[3], argv[4], argv[5]);
    } else if (cmd == "--tail") {
        tail_log();
    } else {
        usage();
        return 1;
    }

    return 0;
}
