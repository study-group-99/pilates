#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtitoa, Zero) {
	EXPECT_STREQ("0",ft_itoa(0)) << "Input: ft_itoa(0)\n";
	EXPECT_STREQ("0",ft_itoa(-0)) << "Input: ft_itoa(-0)\n";
}

TEST(TestFtitoa, Max) {
	EXPECT_STREQ("2147483647",ft_itoa(2147483647)) << "Input: ft_itoa(0)\n";
	EXPECT_STREQ("-2147483648",ft_itoa(-2147483648)) << "Input: ft_itoa(0)\n";
}

TEST(TestFtitoa, PositiveIntegers) {
	EXPECT_STREQ("7",ft_itoa(7)) << "Input: ft_itoa(0)\n";
	EXPECT_STREQ("123",ft_itoa(123)) << "Input: ft_itoa(0)\n";
	EXPECT_STREQ("65432",ft_itoa(65432)) << "Input: ft_itoa(0)\n";
}

TEST(TestFtitoa, NegativeIntegers) {
	EXPECT_STREQ("-7",ft_itoa(-7)) << "Input: ft_itoa(0)\n";
	EXPECT_STREQ("-123",ft_itoa(-123)) << "Input: ft_itoa(0)\n";
	EXPECT_STREQ("-65432",ft_itoa(-65432)) << "Input: ft_itoa(0)\n";
}
