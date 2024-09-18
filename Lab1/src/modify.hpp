#ifndef MODIFY_H
#define MODIFY_H

#include <string>
#include <vector>

std::vector<int> ConvertToVector(const char*, size_t);
std::vector<int> ConvertToVector(const char*);
std::vector<int> ConvertToVector(const std::string&);
std::string ConvertToString(const std::vector<int>&, const std::string&);

#endif