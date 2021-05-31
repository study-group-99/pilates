#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtIsascii, AsciiChars) {
    EXPECT_TRUE(ft_isascii('l'));
    EXPECT_TRUE(ft_isascii('\n'));
    EXPECT_TRUE(ft_isascii(0)); 
    EXPECT_TRUE(ft_isascii(0x1f));
    EXPECT_TRUE(ft_isascii(127)); 
}

TEST(TestFtIsascii, NotAsciiChars) {
    EXPECT_FALSE(ft_isascii(-10));
    EXPECT_FALSE(ft_isascii(-1066965669));
    EXPECT_FALSE(ft_isascii(-1)); 
    EXPECT_FALSE(ft_isascii(0xfa));
    EXPECT_FALSE(ft_isascii(128)); 
}
