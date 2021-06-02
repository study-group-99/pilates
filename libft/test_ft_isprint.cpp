#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtisprint, BsicTest) {
	EXPECT_EQ(0, ft_isprint(0));
	EXPECT_EQ(1, ft_isprint('a'));
	EXPECT_EQ(0, ft_isprint(127));
}
