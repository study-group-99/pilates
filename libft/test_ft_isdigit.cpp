#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtIsdigit, DigitChars) {
    EXPECT_TRUE(ft_isdigit('0')) << "Input: ft_isdigit('0')\n";
    EXPECT_TRUE(ft_isdigit('9')) << "Input: ft_isdigit('9')\n";
    EXPECT_TRUE(ft_isdigit('5')) << "Input: ft_isdigit('5')\n";
    EXPECT_TRUE(ft_isdigit(48)) << "Input: ft_isdigit(48)\n";
    EXPECT_TRUE(ft_isdigit(57)) << "Input: ft_isdigit(57)\n";
    EXPECT_TRUE(ft_isdigit(51)) << "Input: ft_isdigit(51)\n";
    EXPECT_TRUE(ft_isdigit(0x31)) << "Input: ft_isdigit(0x31)\n";
}

TEST(TestFtIsdigit, NotDigitChars) {
    EXPECT_FALSE(ft_isdigit(-48)) << "Input: ft_isdigit(-48)\n";
    EXPECT_FALSE(ft_isdigit(47)) << "Input: ft_isdigit(47)\n";
    EXPECT_FALSE(ft_isdigit(58)) << "Input: ft_isdigit(58)\n";
    EXPECT_FALSE(ft_isdigit(0x3a)) << "Input: ft_isdigit(0x3a)\n";
    EXPECT_FALSE(ft_isdigit('a')) << "Input: ft_isdigit('a')\n";
    EXPECT_FALSE(ft_isdigit('\n')) << "Input: ft_isdigit('\\n')\n";
	EXPECT_FALSE(ft_isdigit(NULL)) << "Input: ft_isdigit(NULL)\n";
}
