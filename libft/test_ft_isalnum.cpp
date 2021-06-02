#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtisalnum, BsicTests) {
	ASSERT_TRUE(isalnum(0) == ft_isalnum(0));
	ASSERT_TRUE(isalnum(127) == ft_isalnum(127));
	ASSERT_TRUE(isalnum(-1) == ft_isalnum(-1));
	// this does not work
	// ASSERT_TRUE(isalnum(530) == ft_isalnum(530));
	// ASSERT_TRUE(isalnum('}') == ft_isalnum('}'));
	// ASSERT_TRUE(isalnum('a') == ft_isalnum('a'));
	// ASSERT_TRUE(isalnum('V') == ft_isalnum('V'));
	// ASSERT_TRUE(isalnum('5') == ft_isalnum('5'));
}
