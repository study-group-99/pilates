#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrlen, SimpleText) {
    char s1[] = "Test123";
    EXPECT_EQ(strlen(s1), ft_strlen(s1));
}

TEST(TestFtStrlen, ZeroText) {
    char s1[] = "";
    EXPECT_EQ(strlen(s1), ft_strlen(s1));
}

TEST(TestFtStrlen, WithSpecChar) {
    char s1[] = "Té:_÷×ßŁst\0T";
    char s2[] = "T\tT";
    EXPECT_EQ(strlen(s1), ft_strlen(s1));
    EXPECT_EQ(strlen(s2), ft_strlen(s2));
}
