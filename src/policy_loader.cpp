#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>
#include <unordered_map>
#include "policy_loader.h"

struct Policy {
    std::string syscall;
    std::string path;
    std::string action;
    std::string reason;
};

static std::vector<Policy> policies;

bool load_policies(const std::string& filepath) {
    try {
        YAML::Node config = YAML::LoadFile(filepath);
        for (const auto& rule : config["policy"]) {
            Policy p;
            p.syscall = rule["match"]["syscall"].as<std::string>();
            p.path    = rule["match"]["path"].as<std::string>();
            p.action  = rule["action"].as<std::string>();
            p.reason  = rule["reason"].as<std::string>();
            policies.push_back(p);
        }
        std::cout << "[Policy] Loaded " << policies.size() << " policies from " << filepath << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "[Policy] Load failed: " << e.what() << std::endl;
        return false;
    }
}

bool matches_policy(const std::string& syscall, const std::string& path) {
    for (const auto& p : policies) {
        if (p.syscall == syscall && path.find(p.path) != std::string::npos) {
            return true;
        }
    }
    return false;
}
