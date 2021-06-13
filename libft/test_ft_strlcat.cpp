#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrlcat, Basic) {
	char got[] = "This is ";
    char s[] = "a potentially long string";

    ft_strlcat(got, s, strlen(got) + strlen(s) + 1);

	EXPECT_STREQ("This is a potentially long string", got);
}

TEST(TestFtStrlcat, Return) {
	char s1[] = "This is ";
    char s2[] = "a potentially long string";

    size_t got = ft_strlcat(s1, s2, strlen(s1) + strlen(s2));

	ASSERT_EQ(33, got);
}

TEST(TestFtStrlcat, Return2) {
	char	s[] = "aaa";
	char	d[20];

	memset(d, 'B', sizeof(d));

	ft_strlcat(d, s, 20);
	ft_strlcat(d, s, 20);
	int got = ft_strlcat(d, s, 20);

	EXPECT_EQ(23, got);
}

TEST(TestFtStrlcat, Max) {
	char s[] = "a short sentence.";
	char got[0xF00] = "another short sentence.";
	size_t max = 1000;

	ft_strlcat(got, s, max);

	EXPECT_STREQ("another short sentence.a short sentence.", got);
}

TEST(TestFtStrlcat, ZeroSize) {
	char s[] = "a short sentence.";
	char got[0xF00] = "another short sentence.";
	size_t max = 0;

	ft_strlcat(got, s, max);

	EXPECT_STREQ("another short sentence.", got);
}

TEST(TestFtStrlcat, ZeroDestination) {
	char s[] = "";
	char got[0xF00] = "another short sentence.";
	size_t max = strlen(got) + 1;

	ft_strlcat(got, s, max);

	EXPECT_STREQ("another short sentence.", got);
}

TEST(TestFtStrlcat, ZeroSource) {
	char s[] = "a short sentence.";
	char got[0xF00] = "";
	size_t max = strlen(s) + 1;

	ft_strlcat(got, s, max);
	EXPECT_STREQ("a short sentence.", got);
}

TEST(TestFtStrlcat, Zero) {
	char s[] = "n\0AA";
	char got[0xF00] = "\0AAAAAAAAAAAAAAAA";
	size_t max = 10;

	ft_strlcat(got, s, max);
	EXPECT_STREQ("n", got);
}
