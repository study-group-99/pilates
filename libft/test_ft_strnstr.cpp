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

    EXPECT_EQ(want[0], *ft_strnstr(want, s1, 9)) << "Input: *ft_strnstr(\"seme test\", \"\", 9);";

    EXPECT_EQ(want[3], *ft_strnstr(want, s2, 9)) << "Input: *ft_strnstr(\"seme test\", \"e\", 9);";

    EXPECT_EQ(want[3], *ft_strnstr(want, s3, 9)) << "Input: *ft_strnstr(\"seme test\", \"e \", 9);";

    EXPECT_EQ(want[3], *ft_strnstr(want, s4, 9)) << "Input: *ft_strnstr(\"seme test\", \"e tex\", 9);";

    EXPECT_EQ(NULL, ft_strnstr(want, s5, 9)) << "Input: *ft_strnstr(\"seme test\", \"Va63\", 9);";

    EXPECT_EQ(NULL, ft_strnstr(s2, want, 9)) << "Input: *ft_strnstr(\"e\", \"seme test\", 9);";

    EXPECT_EQ(NULL, ft_strnstr(s3, want, 9)) << "Input: *ft_strnstr(\"e \", \"seme test\", 9);";

    EXPECT_EQ(NULL, ft_strnstr(s4, want, 9)) << "Input: *ft_strnstr(\"e \", \"seme test\", 9);";

    EXPECT_EQ(NULL, ft_strnstr(s5, want, 9)) << "Input: *ft_strnstr(\"Va63\", \"seme test\", 9);";
}

TEST(TestFtStrnstr, Extra) {
	EXPECT_TRUE(NULL == ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 10)) << "Input: ft_strnstr(\"lorem ipsum dolor sit amet\", \"ipsumm\", 10);";
	EXPECT_TRUE('d' == *ft_strnstr("lorem ipsum dolor sit amet", "dol", 30)) << "Input: ft_strnstr(\"lorem ipsum dolor sit amet\", \"dol\", 10);";
	EXPECT_STREQ(NULL, ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30)) << "Input: ft_strnstr(\"lorem ipsum dolor sit amet\", \"consectetur\", 10);";
}

TEST(TestFtStrnstr, NotFound) {
	char s1[] = "FF";
	char s2[] = "see FF your FF return FF now FF";
	char *got = ft_strnstr(s1, s2, 4);
	EXPECT_EQ(NULL, got) << "Input: char *got = ft_strnstr(\"FF\", \"see FF your FF return FF now FF\", 4);";
}

TEST(TestFtStrnstr, EmptyDestination) {
	char s1[] = "";
	char s2[] = "lorem ipsum dolor !";
	size_t max = strlen(s2);
	char *got = ft_strnstr(s1, s2, max);
	EXPECT_EQ(NULL, got) << "Input: char *got = ft_strnstr(\"lorem ipsum dolor !\", \"\", 20);";
}

TEST(TestFtStrnstr, EmptySource) {
	char s1[] = "lorem ipsum dolor !";
	char s2[] = "";
	size_t max = strlen(s1);
	char *got = ft_strnstr(s1, s2, max);
	EXPECT_TRUE('l' == *got) << "Input: char *got = ft_strnstr(\"lorem ipsum dolor !\", \"\", 20);";
}

TEST(TestFtStrnstr, ZeroLength) {
	char s1[] = "lorem ipsum dolor !";
	char s2[] = "";
	char *got = ft_strnstr(s1, s2, 0);
	EXPECT_TRUE('l' == *got) << "Input: char *got = ft_strnstr(\"lorem ipsum dolor !\", \"\", 0);";
}

TEST(TestFtStrnstr, ZeroLength2) {
	char s1[] = "";
	char s2[] = "lorem ipsum dolor !";
	char *got = ft_strnstr(s1, s2, 0);
	EXPECT_TRUE(NULL == got) << "Input: char *got = ft_strnstr( \"\", \"lorem ipsum dolor !\", 0);";
}

TEST(TestFtStrnstr, Same) {
	char s[] = "AAAAAAAAAAAAA";
	size_t max = strlen(s);
	char *got = ft_strnstr(s, s, max);
	EXPECT_TRUE('A' == *got) << "Input: char *got = ft_strnstr(\"AAAAAAAAAAAAA\", \"AAAAAAAAAAAAA\", 14);";
}

TEST(TestFtStrnstr, BiggerLength) {
	char *got = ft_strnstr("A", "A", 2);
	EXPECT_TRUE('A' == *got) << "Input: char *got = ft_strnstr(\"A\", \"A\", 0);";
}
