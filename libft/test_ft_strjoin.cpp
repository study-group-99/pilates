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
	char s1[] = "Some text in string 1..";
	char s2[] = "";
	char expected_result[] = "Some text in string 1..";
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
