#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtToupper, AlfaChars) {
    EXPECT_TRUE(tolower('a') == ft_tolower('a'));
    EXPECT_TRUE(tolower('f') == ft_tolower('f'));
    EXPECT_TRUE(tolower('z') == ft_tolower('z'));
    EXPECT_TRUE(tolower('A') == ft_tolower('A'));
    EXPECT_TRUE(tolower('Z') == ft_tolower('Z'));
}

TEST(TestFtToupper, AsciiChars) {
    EXPECT_TRUE(tolower('-') == ft_tolower('-'));
    EXPECT_TRUE(tolower('0') == ft_tolower('0'));
    EXPECT_TRUE(tolower('\n') == ft_tolower('\n'));
}