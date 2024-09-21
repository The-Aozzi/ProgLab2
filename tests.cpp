#include <gtest/gtest.h>
#include "utils.h"
#include <sstream>

TEST(make_ip, make_ip)
{
    EXPECT_EQ(make_ip("127.0.0.1"), ip_t(127, 0, 0, 1));
    EXPECT_EQ(make_ip("255.255.255.255SomeTrash"), ip_t(255, 255, 255, 255));
    EXPECT_EQ(make_ip("0.0.0.0.1.2"), ip_t(01, 0, 0, 0));
}

TEST(print_ip, print_ip)
{
    std::stringstream stream;

    print_ip(ip_t(127, 0, 0, 1), stream);
    EXPECT_EQ(stream.str(), "127.0.0.1\n");
    stream.str("");

    print_ip(ip_t(255, 255, 255, 255), stream);
    EXPECT_EQ(stream.str(), "255.255.255.255\n");
    stream.str("");

    print_ip(ip_t(8, 8, 8, 8), stream);
    EXPECT_EQ(stream.str(), "8.8.8.8\n");
    stream.str("");
}

TEST(CompareIp, CompareIp)
{
    CompareIp cmp;
    EXPECT_TRUE(cmp(ip_t(1, 1, 1, 1), ip_t(1, 2, 1, 1)));
    EXPECT_TRUE(cmp(ip_t(1, 2, 1, 1), ip_t(1, 10, 1, 1)));
    EXPECT_FALSE(cmp(ip_t(1, 1, 1, 1), ip_t(1, 1, 1, 1)));
}