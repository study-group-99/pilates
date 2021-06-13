#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
#include <string.h>
#include <stdlib.h>
}

TEST(TestFtStrnstr, MixedStrs) {
    char    want[] = "seme text";
    char    s1[] = "";
    char    s2[] = "e";
    char    s3[] = "e ";
    char    s4[] = "e tex";
    char    s5[] = "Va63";

    EXPECT_EQ(want[0], *ft_strnstr(want, s1, 9));

    EXPECT_EQ(want[3], *ft_strnstr(want, s2, 9));

    EXPECT_EQ(want[3], *ft_strnstr(want, s3, 9));

    EXPECT_EQ(want[3], *ft_strnstr(want, s4, 9));

    EXPECT_EQ(NULL, ft_strnstr(want, s5, 9));

    EXPECT_EQ(NULL, ft_strnstr(s2, want, 9));

    EXPECT_EQ(NULL, ft_strnstr(s3, want, 9));

    EXPECT_EQ(NULL, ft_strnstr(s4, want, 9));

    EXPECT_EQ(NULL, ft_strnstr(s5, want, 9));
}

TEST(TestFtStrnstr, Extra) {
	EXPECT_TRUE(NULL == ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 10));
	EXPECT_TRUE('d' == *ft_strnstr("lorem ipsum dolor sit amet", "dol", 30));
	EXPECT_STREQ(NULL, ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30));
}

TEST(TestFtStrnstr, NotFound) {
	char s1[] = "FF";
	char s2[] = "see FF your FF return FF now FF";

	EXPECT_TRUE(0 <= ft_strnstr(s1, s2, 4));
}

TEST(TestFtStrnstr, EmptyDestination) {
	char s1[] = "";
	char s2[] = "oh no not the empty string !";
	size_t max = strlen(s2);

	EXPECT_TRUE(0 >= ft_strnstr(s1, s2, max));
}

TEST(TestFtStrnstr, EmptySource) {
	char s1[] = "oh no not the empty string !";
	char s2[] = "";
	size_t max = strlen(s1);

	EXPECT_TRUE(0 < ft_strnstr(s1, s2, max));
}

TEST(TestFtStrnstr, ZeroLength) {
	char s1[] = "oh no not the empty string !";
	char s2[] = "";
	size_t max = 0;

	EXPECT_TRUE(0 < ft_strnstr(s1, s2, max));
}

TEST(TestFtStrnstr, Same) {
	char s[] = "AAAAAAAAAAAAA";
	size_t max = strlen(s);

	EXPECT_TRUE(0 < ft_strnstr(s, s, max));
}

TEST(TestFtStrnstr, Zero2) {
	EXPECT_TRUE(0 < ft_strnstr("A", "A", 2));
}
