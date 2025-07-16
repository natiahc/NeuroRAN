#include <iostream>
#include "../include/causal_logger.h"

int main() {
    std::cout << "[Test] Logging simulated events...\n";

    log_event("AUDIT", "execve", "/usr/bin/python3", "Interpreter launched");
    log_event("DENY", "execve", "/usr/bin/nc", "Netcat blocked");
    log_event("ALLOW", "open", "/models/scan_model.onnx", "Model used");

    std::cout << "[Test] Logger test completed ✅\n";
    return 0;
}
