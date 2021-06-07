#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtIsascii, AsciiChars) {
    EXPECT_TRUE(ft_isascii('l')) << "Input: ft_isascii('l')\n";
    EXPECT_TRUE(ft_isascii('\n')) << "Input: ft_isascii('\\\n')\n";
    EXPECT_TRUE(ft_isascii(0)) << "Input: ft_isascii(0)\n";
    EXPECT_TRUE(ft_isascii(0x1f)) << "Input: ft_isascii(0x1f)\n";
    EXPECT_TRUE(ft_isascii(127)) << "Input: ft_isascii(127)\n";
	EXPECT_TRUE(ft_isascii(NULL)) << "Input: ft_isascii(NULL)\n";
}

TEST(TestFtIsascii, NotAsciiChars) {
    EXPECT_FALSE(ft_isascii(-10)) << "Input: ft_isascii(-10)\n";
    EXPECT_FALSE(ft_isascii(-1066965669)) << "Input: ft_isascii(-1066965669)\n";
    EXPECT_FALSE(ft_isascii(-1)) << "Input: ft_isascii(-1)\n";
    EXPECT_FALSE(ft_isascii(0xfa)) << "Input: ft_isascii(0xfa)\n";
    EXPECT_FALSE(ft_isascii(128)) << "Input: ft_isascii(128)\n";
}
