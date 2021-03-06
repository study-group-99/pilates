#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtToupper, AlfaChars) {
    EXPECT_TRUE(toupper('a') == ft_toupper('a')) << "Input: ft_toupper('a')";
    EXPECT_TRUE(toupper('f') == ft_toupper('f')) << "Input: ft_toupper('f')";
    EXPECT_TRUE(toupper('z') == ft_toupper('z')) << "Input: ft_toupper('z')";
    EXPECT_TRUE(toupper('A') == ft_toupper('A')) << "Input: ft_toupper('A')";
    EXPECT_TRUE(toupper('Z') == ft_toupper('Z')) << "Input: ft_toupper('Z')";
}

TEST(TestFtToupper, AsciiChars) {
    EXPECT_TRUE(toupper('-') == ft_toupper('-')) << "Input: ft_toupper('-')";
    EXPECT_TRUE(toupper('0') == ft_toupper('0')) << "Input: ft_toupper('0')";
    EXPECT_TRUE(toupper('\n') == ft_toupper('\n')) << "Input: ft_toupper('\\n')";
}
