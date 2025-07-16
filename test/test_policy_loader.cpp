#include <cassert>
#include <iostream>
#include "../include/policy_loader.h"

int main() {
    std::string test_policy = "test/test_policy.yaml";
    bool loaded = load_policies(test_policy);
    assert(loaded && "Policy loading failed");

    assert(matches_policy("execve", "/usr/bin/nc") && "Expected match for netcat");
    assert(!matches_policy("execve", "/usr/bin/curl") && "Unexpected match");

    std::cout << "[Test] Policy loader passed ✅\n";
    return 0;
}
