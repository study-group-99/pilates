#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrdup, Simple) {
    char want[] = "Test";
    char *got = ft_strdup(want);
    EXPECT_STREQ(want, got) << "Input: ft_strdup(\"Test\");";
}

TEST(TestFtStrdup, Simple2) {
	char want[] = "ThislkjeO4jml5knlnlt";
    char *got = ft_strdup(want);
	EXPECT_STREQ(want, got) << "Input: ft_strdup(\"ThislkjeO4jml5knlnlt\");";
}

TEST(TestFtStrdup, Zero) {
    char want[] = "";
    char *got = ft_strdup(want);
    EXPECT_STREQ(want, got) << "Input: ft_strdup(\"\");";
}

TEST(TestFtStrdup, CopyUntilTerminator) {
    char s[] = "ThislkjeO4jml5\0knlnlt";
    char *want = strdup(s);
	char *got = ft_strdup(s);
    EXPECT_STREQ(want, got) << "Input: ft_strdup(\"ThislkjeO4jml5\\0knlnlt\");";
}

TEST(TestFtStrdup, Complex) {
    char s[] = "ghreuh gkF\tEs1eáéa24j7\v ß\\zk9jF?U+h\0x33+5krfwfeefkkkkk";
    char *want = strdup(s);
	char *got = ft_strdup(s);
    EXPECT_STREQ(want, got) << "Input: ft_strdup(\"ghreuh gkF\\tEs1eáéa24j7\\v ß\\\\zk9jF?U+h\\0x33+5krfwfeefkkkkk\");";
}
