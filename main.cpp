#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <queue>
#include <algorithm>
#include "utils.h"

int main(int, char **)
{
    std::ifstream file("./ip_filter.tsv");
    if (!file)
    {
        std::cerr << "Could not open file './ip_filter.tsv'!";
        return -1;
    }

    std::priority_queue<ip_t, std::vector<ip_t>, CompareIp> ip_queue;

    for (std::string line; std::getline(file, line);)
    {
        auto ip = make_ip(line);
        ip_queue.push(ip);
    }

    file.close();

    std::vector<ip_t> ip_list;

    while (!ip_queue.empty())
    {
        ip_list.push_back(ip_queue.top());
        print_ip(ip_queue.top());
        ip_queue.pop();
    }

    std::for_each(ip_list.begin(), ip_list.end(), [](ip_t ip)
                  {if (std::get<0>(ip) == 1) print_ip(ip); });

    std::for_each(ip_list.begin(), ip_list.end(), [](ip_t ip)
                  {if (std::get<0>(ip) == 46 && std::get<1>(ip) == 70) print_ip(ip); });

    std::for_each(ip_list.begin(), ip_list.end(), [](ip_t ip)
                  {if (std::get<0>(ip) == 46 || std::get<1>(ip) == 46 || std::get<2>(ip) == 46 || std::get<3>(ip) == 46) print_ip(ip); });
}
