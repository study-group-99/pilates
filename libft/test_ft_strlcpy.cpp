#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrlcpy, Basic) {
	char want[] = "Hello there, Mate";
    char got[19];

	ft_strlcpy(got, want, strlen(want) + 1);
    
	EXPECT_STREQ(want, got) << "Input: char want[] = \"Hello there, Mate\"; char got[19]; ft_strlcpy(got, want, strlen(want) + 1);";
}

TEST(TestFtStrlcpy, BasicReturn) {
	char s1[] = "Hello there, Mate";
    char s2[19];

	size_t got = ft_strlcpy(s2, s1, strlen(s1) + 1);
    
	EXPECT_EQ(17, got) << "Input: char want[] = \"Hello there, Mate\"; char got[19]; ft_strlcpy(got, want, strlen(want) + 1);";
}

TEST(TestFtStrlcpy, SomeCharacters) {
    const char s[] = "Test123";
	char got[] = {};

	ft_strlcpy(got, s, 2);

    EXPECT_STREQ("T", got) << "Input: const char s[] = \"Test123\"; char got[] = {}; ft_strlcpy(got, s, 2);";
}

TEST(TestFtStrlcpy, ZeroLengthSource) {
	char s[] = "";
	char got[0xF00];

	memset(got, 'A', 20);

	size_t got1 = ft_strlcpy(got, s, sizeof(got));
	EXPECT_STREQ("", got) << "Input: char s[] = \"\"; char got[0xF00]; memset(got, 'A', 20); size_t got1 = ft_strlcpy(got, s, sizeof(got));";
	EXPECT_EQ(0, got1) << "Input: char s[] = \"\"; char got[0xF00]; memset(got, 'A', 20); size_t got1 = ft_strlcpy(got, s, sizeof(got));";
}

TEST(TestFtStrlcpy, Overflow) {
	char s[] = "BBBB";
	char got[0xF00];

	memset(got, 'A', 20);

	ft_strlcpy(got, s, sizeof(got));

	EXPECT_STREQ("BBBB", got) << "Input: char s[] = \"BBBB\"; char got[0xF00]; memset(got, 'A', 20); ft_strlcpy(got, s, sizeof(got));";
}

TEST(TestFtStrlcpy, NoCharacters) {
    const char yo[] = {};
	char dst[] = {};

    EXPECT_EQ(0, ft_strlcpy(dst, yo, 0));
    EXPECT_EQ(*yo, *dst) << "Input: const char yo[] = {}; char dst[] = {}; ft_strlcpy(dst, yo, 0));";
}

TEST(TestFtStrlcpy, ZeroLength) {
	char s[] = "BBBB";
	char got[0xF00] = "AAAAAAAAAAAAAAAAAAAA";

	ft_strlcpy(got, s, 0);
	
	EXPECT_STREQ("AAAAAAAAAAAAAAAAAAAA", got) << "Input: char s[] = \"BBBB\";	char got[0xF00] = \"AAAAAAAAAAAAAAAAAAAA\"; ft_strlcpy(got, s, 0);";
}
