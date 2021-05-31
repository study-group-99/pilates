#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtIsdigit, DigitChars) {
    EXPECT_TRUE(ft_isdigit('0'));
    EXPECT_TRUE(ft_isdigit('9'));
    EXPECT_TRUE(ft_isdigit('5'));
    EXPECT_TRUE(ft_isdigit(48));
    EXPECT_TRUE(ft_isdigit(57));
    EXPECT_TRUE(ft_isdigit(51));
    EXPECT_TRUE(ft_isdigit(0x31));
}

TEST(TestFtIsdigit, NotDigitChars) {
    EXPECT_FALSE(ft_isdigit(-48));
    EXPECT_FALSE(ft_isdigit(47));
    EXPECT_FALSE(ft_isdigit(58)); 
    EXPECT_FALSE(ft_isdigit(0x3a));
    EXPECT_FALSE(ft_isdigit('a')); 
    EXPECT_FALSE(ft_isdigit('\n')); 
}
