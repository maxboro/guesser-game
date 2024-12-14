#ifndef UTILS_H
#define UTILS_H

#include <unordered_map>

using namespace std;

unordered_map<string, int> read_config();
bool ask_for_rerun();

#endif