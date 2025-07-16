#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <openssl/sha.h>
#include "causal_logger.h"

static std::string last_hash = "000000";

std::string get_timestamp() {
    std::time_t t = std::time(nullptr);
    std::stringstream ss;
    ss << std::put_time(std::gmtime(&t), "%FT%TZ");
    return ss.str();
}

std::string compute_hash(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)input.c_str(), input.size(), hash);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    return ss.str();
}

void log_event(const std::string& action, const std::string& syscall,
               const std::string& target, const std::string& reason) {
    std::ofstream log("neuroran_events.log", std::ios::app);
    std::string timestamp = get_timestamp();

    std::stringstream record;
    record << timestamp << "," << action << "," << syscall << "," << target << "," << reason << "," << last_hash;
    std::string new_hash = compute_hash(record.str());

    log << record.str() << "," << new_hash << std::endl;
    last_hash = new_hash;

    std::cout << "[Logger] " << action << " " << syscall << " on " << target << " — " << reason << std::endl;
}
