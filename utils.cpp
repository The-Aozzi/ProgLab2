#include "utils.h"

ip_t make_ip(const std::string &str)
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

void print_ip(ip_t ip, std::ostream& out)
{
    out << +std::get<0>(ip) << '.'
        << +std::get<1>(ip) << '.'
        << +std::get<2>(ip) << '.'
        << +std::get<3>(ip) << '\n';
}

    bool CompareIp::operator()(const ip_t &left, const ip_t &right)
    {
        // clang-format off
        return std::get<0>(left) != std::get<0>(right) ? std::get<0>(left) < std::get<0>(right)
             : std::get<1>(left) != std::get<1>(right) ? std::get<1>(left) < std::get<1>(right)
             : std::get<2>(left) != std::get<2>(right) ? std::get<2>(left) < std::get<2>(right)
             : std::get<3>(left) != std::get<3>(right) ? std::get<3>(left) < std::get<3>(right)
                                                       : false;
        // clang-format on
    }