#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtisalnum, Basic) {
	EXPECT_TRUE(isalnum(0) == ft_isalnum(0)) << "Input: isalnum(0)\n";
	EXPECT_TRUE(isalnum(127) == ft_isalnum(127)) << "Input: isalnum(127)\n";
	EXPECT_TRUE(isalnum(-1) == ft_isalnum(-1)) << "Input: isalnum(-1)\n";

	EXPECT_TRUE(isalnum('#') == ft_isalnum('#')) << "Input: isalnum('#')\n";
	EXPECT_TRUE(isalnum('^') == ft_isalnum('^')) << "Input: isalnum('^')\n";
}
