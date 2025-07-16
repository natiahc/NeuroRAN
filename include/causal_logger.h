#ifndef CAUSAL_LOGGER_H
#define CAUSAL_LOGGER_H

#include <string>

// Log an event with action (ALLOW, DENY, AUDIT), syscall name, file/socket path, and reason
void log_event(const std::string& action,
               const std::string& syscall,
               const std::string& target,
               const std::string& reason);

#endif // CAUSAL_LOGGER_H
