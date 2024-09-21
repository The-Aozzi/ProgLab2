#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <queue>
#include <algorithm>

using ip_t = std::tuple<unsigned char, unsigned char, unsigned char, unsigned char>;

ip_t make_ip(const std::string &str);

void print_ip(ip_t ip, std::ostream &out = std::cout);

struct CompareIp
{
    bool operator()(const ip_t &left, const ip_t &right);
};

#endif