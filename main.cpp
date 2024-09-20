#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <queue>
#include <algorithm>

auto make_ip(const std::string &str)
{
    std::tuple result;
    std::size_t index;
    std::size_t index_abs = -1;
    unsigned char values[4] = {0};
    for (int i = 0; i < 4; ++i)
    {
        index_abs++;
        auto c_str = str.c_str() + index_abs;
        values[i] = std::stoi(c_str, &index);
        index_abs += index;
    }
    return std::make_tuple(values[0], values[1], values[2], values[3]);
}
using ip_t = std::invoke_result_t<decltype(make_ip), const std::string &>;

void print_ip(auto ip, std::ostream& out = std::cout)
{
    out << +std::get<0>(ip) << '.'
        << +std::get<1>(ip) << '.'
        << +std::get<2>(ip) << '.'
        << +std::get<3>(ip) << '\n';
}

struct CompareIp
{
    bool operator()(const ip_t &left, const ip_t &right)
    {
        // clang-format off
        return std::get<0>(left) != std::get<0>(right) ? std::get<0>(left) < std::get<0>(right)
             : std::get<1>(left) != std::get<1>(right) ? std::get<1>(left) < std::get<1>(right)
             : std::get<2>(left) != std::get<2>(right) ? std::get<2>(left) < std::get<2>(right)
             : std::get<3>(left) != std::get<3>(right) ? std::get<3>(left) < std::get<3>(right)
                                                       : false;
        // clang-format on
    }
};

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
