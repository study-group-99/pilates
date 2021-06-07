#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrjoin, SimpleStr) {
	char s1[] = "Some text in string 1..";
	char s2[] = "another text in string 2 aushd";
	char expected_result[] = "Some text in string 1..another text in string 2 aushd";
	char *c1;

	c1 = ft_strjoin(s1, s2);
	ASSERT_TRUE(c1 != 0);
	EXPECT_EQ(0, strcmp(c1, expected_result));
	EXPECT_EQ(strlen(c1), strlen(expected_result));
	free(c1);
}

TEST(TestFtStrjoin, BothZeroStr) {
	char s1[] = "";
	char s2[] = "";
	char expected_result[] = "";
	char *c1;

	c1 = ft_strjoin(s1, s2);
	ASSERT_TRUE(c1 != 0);
	EXPECT_EQ(0, strcmp(c1, expected_result));
	EXPECT_EQ(strlen(c1), strlen(expected_result));
	free(c1);
}

TEST(TestFtStrjoin, FirstZeroStr) {
	char s1[] = "";
	char s2[] = "another text in string 2 aushd";
	char expected_result[] = "another text in string 2 aushd";
	char *c1;

	c1 = ft_strjoin(s1, s2);
	ASSERT_TRUE(c1 != 0);
	EXPECT_EQ(0, strcmp(c1, expected_result));
	EXPECT_EQ(strlen(c1), strlen(expected_result));
	free(c1);
}

TEST(TestFtStrjoin, SecondZeroStr) {
	char *s1 = "Some text in string 1..";
	char *s2 = "";
	char *expected_result = "Some text in string 1..";
	char *c1;

	c1 = ft_strjoin(s1, s2);
	ASSERT_TRUE(c1 != 0);
	EXPECT_EQ(0, strcmp(c1, expected_result));
	EXPECT_EQ(strlen(c1), strlen(expected_result));
	free(c1);
}

TEST(TestFtStrjoin, Nested) {
	char	*s1 = "my favorite animal is";
	char	*s2 = " ";
	char	*s3 = "the nyancat";

	char	*res = ft_strjoin(ft_strjoin(s1, s2), s3);
	ASSERT_STREQ(res, "my favorite animal is the nyancat");
}

TEST(TestFtStrjoin, Free) {
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";

	char*tmp = ft_strjoin(s1, s2);
	char *got = ft_strjoin(tmp, s3);
	free(tmp);
	EXPECT_STREQ("my favorite animal is the nyancat", got);
}

TEST(TestFtStrjoin, Overlap) {
	char *want = "my favorite animal is ";
	char *s = want + 20;

	char *got = ft_strjoin(s, want);
	EXPECT_STREQ("s my favorite animal is ", got);
}

TEST(TestFtStrjoin, MustSegfault) {
	EXPECT_EXIT((ft_strjoin(NULL, "where is my "), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strjoin(NULL, \"where is my \");\n";
	EXPECT_EXIT((ft_strjoin("where is my ", NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strjoin(\"where is my \", NULL);\n";
	EXPECT_EXIT((ft_strjoin(NULL, NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strjoin(NULL, NULL);\n";
}
