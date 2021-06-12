#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrlcpy, Basic) {
	char want[] = "Hello there, Venus";
    char got[19];

	ft_strlcpy(got, want, strlen(want) + 1);
    
	EXPECT_STREQ(want, got);
}

TEST(TestFtStrlcpy, BasicReturn) {
	char s1[] = "Hello there, Venus";
    char s2[19];

	size_t got = ft_strlcpy(s2, s1, strlen(s1) + 1);
    
	EXPECT_EQ(18, got);
}

TEST(TestFtStrlcpy, SomeCharacters) {
    const char s[] = "Test123";
	char got[] = {};

	ft_strlcpy(got, s, 2);

    EXPECT_STREQ("T", got);
}

TEST(TestFtStrlcpy, ZeroLengthSource) {
	char s[] = "";
	char got[0xF00];

	memset(got, 'A', 20);

	size_t got1 = ft_strlcpy(got, s, sizeof(got));
	EXPECT_STREQ("", got);
	EXPECT_EQ(0, got1);
}

TEST(TestFtStrlcpy, Overflow) {
	char s[] = "BBBB";
	char got[0xF00];

	memset(got, 'A', 20);

	ft_strlcpy(got, s, sizeof(got));

	EXPECT_STREQ("BBBB", got);
}

TEST(TestFtStrlcpy, NoCharacters) {
    const char yo[] = {};
	char dst[] = {};

    EXPECT_EQ(0, ft_strlcpy(dst, yo, 0));
    EXPECT_EQ(*yo, *dst);
}

TEST(TestFtStrlcpy, ZeroLength) {
	char s[] = "BBBB";
	char got[0xF00] = "AAAAAAAAAAAAAAAAAAAA";

	ft_strlcpy(got, s, 0);
	
	EXPECT_STREQ("AAAAAAAAAAAAAAAAAAAA", got);
}

TEST(TestFtStrlcpy, MustSegfault) {
	EXPECT_EXIT((ft_strlcpy(NULL, NULL, 10), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strlcpy(NULL, NULL, 10);\n";
}
