#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrdup, SimpleStr) {
    char *want = "Test";
    char *got = ft_strdup(want);
    EXPECT_STREQ(want, got);

	want = "ThislkjeO4jml5knlnlt";
    got = ft_strdup(want);
	EXPECT_STREQ(want, got);
}

TEST(TestFtStrdup, ZeroStr) {
    char *want = "";
    char *got = ft_strdup(want);
    EXPECT_STREQ(want, got);
}

TEST(TestFtStrdup, CopyUntilTerminator) {
    char *s = "ThislkjeO4jml5\0knlnlt";
    char *want = strdup(s);
	char *got = ft_strdup(s);
    EXPECT_STREQ(want, got);
}

TEST(TestFtStrdup, ComplexStr) {
    char *s = "ghreuh gkF\tEs1eáéa24j7\v ß\\zk9jF?U+h\0x33+5krfwfeefkkkkk";
    char *want = strdup(s);
	char *got = ft_strdup(s);
    EXPECT_STREQ(want, got);
}

TEST(TestFtStrchr, MustSegfault) {
	EXPECT_EXIT((ft_strdup(NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strdup(NULL);\n";
}
