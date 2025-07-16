#ifndef POLICY_LOADER_H
#define POLICY_LOADER_H

#include <string>

// Load all policy rules from a YAML config file
bool load_policies(const std::string& filepath);

// Check if a syscall + path matches any loaded policy
bool matches_policy(const std::string& syscall, const std::string& path);

#endif // POLICY_LOADER_H
