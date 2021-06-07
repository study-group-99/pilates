#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtisalpha, Basic) {
	EXPECT_TRUE(0 < ft_isalpha('a')) << "Input: ft_isalpha('a')\n";
	EXPECT_TRUE(0 < ft_isalpha('O')) << "Input: ft_isalpha('O')\n";

	EXPECT_TRUE(0 >= ft_isalpha(0)) << "Input: ft_isalpha(0)\n";
	EXPECT_TRUE(0 >= ft_isalpha(127)) << "Input: ft_isalpha(127)\n";
	EXPECT_TRUE(0 >= ft_isalpha(-1)) << "Input: ft_isalpha(-1)\n";

	EXPECT_TRUE(0 >= ft_isalpha('#')) << "Input: ft_isalpha('#')\n";
	EXPECT_TRUE(0 >= ft_isalpha('^')) << "Input: ft_isalpha('^')\n";
}
