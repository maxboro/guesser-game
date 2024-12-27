#ifndef UTILS_H
#define UTILS_H

#include <unordered_map>

std::unordered_map<std::string, int> read_config();

// Ask user for rerun and process answer
bool ask_for_rerun();

std::string get_current_timestamp_ms();

int get_current_timestamp();

#endif
