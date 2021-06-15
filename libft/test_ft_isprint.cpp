#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtisprint, Bsic) {
	EXPECT_TRUE(ft_isprint('a')) << "Input: ft_isprint('a')\n";
	EXPECT_TRUE(ft_isprint('Z')) << "Input: ft_isprint('Z')\n";
	EXPECT_FALSE(ft_isprint(0)) << "Input: ft_isprint(0)\n";
	EXPECT_FALSE(ft_isprint(127)) << "Input: ft_isprint(127)\n";
}
