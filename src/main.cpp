#include <iostream>
#include "policy_loader.h"
#include "syscall_monitor.h"
#include "causal_logger.h"

int main(int argc, char* argv[]) {
    std::cout << "[NeuroRAN] Initializing runtime agent..." << std::endl;

    // Load security and inference policies
    std::string policyPath = "/etc/neuroran/default-policy.yaml";
    if (!load_policies(policyPath)) {
        std::cerr << "[NeuroRAN] Failed to load policy from: " << policyPath << std::endl;
        return 1;
    }

    // Initialize syscall monitor
    if (!start_syscall_monitor()) {
        std::cerr << "[NeuroRAN] Syscall monitoring failed to start." << std::endl;
        return 2;
    }

    // Main agent loop (could use event loop later)
    std::cout << "[NeuroRAN] Agent running. Press Ctrl+C to exit." << std::endl;
    while (true) {
        // Placeholder — could handle periodic updates, metrics, etc.
        sleep(10);
    }

    return 0;
}
