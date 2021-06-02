#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtitoa, Zero) {
	EXPECT_EQ(0, strcmp("0",ft_itoa(0)));
	EXPECT_EQ(0, strcmp("0",ft_itoa(-0)));
}

TEST(TestFtitoa, IntRange) {
	EXPECT_EQ(0, strcmp("2147483647",ft_itoa(2147483647)));
	EXPECT_EQ(0, strcmp("-2147483648",ft_itoa(-2147483648)));
}

TEST(TestFtitoa, PositiveIntegers) {
	EXPECT_EQ(0, strcmp("7",ft_itoa(7)));
	EXPECT_EQ(0, strcmp("123",ft_itoa(123)));
	EXPECT_EQ(0, strcmp("65432",ft_itoa(65432)));
}

TEST(TestFtitoa, NegativeIntegers) {
	EXPECT_EQ(0, strcmp("-7",ft_itoa(-7)));
	EXPECT_EQ(0, strcmp("-123",ft_itoa(-123)));
	EXPECT_EQ(0, strcmp("-65432",ft_itoa(-65432)));
}

TEST(TestFtitoa, SomeExtra) {
	ASSERT_STREQ("-623",ft_itoa(-623));
	ASSERT_STREQ("156",ft_itoa(156));
	ASSERT_STREQ("0",ft_itoa(-0));
	EXPECT_EQ(0, strcmp(ft_itoa(156), "156"));
	if (strcmp(ft_itoa(156), "156"))
		EXPECT_EQ(0, 1);
}
