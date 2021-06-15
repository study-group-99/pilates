#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtTolower, AlfaChars) {
    EXPECT_TRUE(tolower('a') == ft_tolower('a')) << "Input: ft_tolower('a')";
    EXPECT_TRUE(tolower('f') == ft_tolower('f')) << "Input: ft_tolower('f')";
    EXPECT_TRUE(tolower('z') == ft_tolower('z')) << "Input: ft_tolower('z')";
    EXPECT_TRUE(tolower('A') == ft_tolower('A')) << "Input: ft_tolower('A')";
    EXPECT_TRUE(tolower('Z') == ft_tolower('Z')) << "Input: ft_tolower('Z')";
}

TEST(TestFtTolower, AsciiChars) {
    EXPECT_TRUE(tolower('-') == ft_tolower('-')) << "Input: ft_tolower('-')";
    EXPECT_TRUE(tolower('0') == ft_tolower('0')) << "Input: ft_tolower('0')";
    EXPECT_TRUE(tolower('\n') == ft_tolower('\n')) << "Input: ft_tolower('\\n')";
}
