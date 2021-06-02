#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtSubstr, SimpleStr1) {
    char testString[] = "this is a string";
    char *retVal;

    retVal = ft_substr(testString, 2, 5);
    ASSERT_STREQ(retVal, "is is") << "1";
	free(retVal);
}

TEST(TestFtSubstr, SimpleStr2) {
    char testString[] = "this is a string";
    char *retVal;

    retVal = ft_substr(testString, 10, 5);
    ASSERT_STREQ(retVal, "strin") << "1";
	free(retVal);
}

TEST(TestFtSubstr, EmptyStr) {
    char testString[] = "";
    char *retVal;

    retVal = ft_substr(testString, 0, 0);
    ASSERT_STREQ(retVal, "") << "1";
	free(retVal);
}

TEST(TestFtSubstr, EmptyStr2) {
    char testString[] = "";
    char *retVal;

    retVal = ft_substr(testString, 1, 1);
    ASSERT_STREQ(retVal, "") << "1";
	free(retVal);
}

TEST(TestFtSubstr, ZeroStr) {
    char s1[] = "";
    char s2[] = "ThislkjeO4jml5knlnlt";
    char *c1, *c2;

    c1 = ft_substr(s1, 0, 3);
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1,s1));
    EXPECT_EQ(strlen(s1), strlen(c1));
    free(c1);
    c2 = ft_substr(s2, 10, 0);
    EXPECT_EQ(0, strcmp(c2, s1));
    EXPECT_EQ(strlen(s1), strlen(c2));
    free(c2);
}

TEST(TestFtSubstr, CopyUntilTerminator) {
    char s1[] = "ThislkjeO4jml5\0knlnlt";
    char s2[] = "ThislkjeO4jml5";
    char s3[] = "";
    char *c1, *c2, *c3;

    c1 = ft_substr(s1, 0, 50);
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, s2));
    EXPECT_EQ(strlen(c1), strlen(s2));
    free(c1);
    c2 = ft_substr(s2, 14, 10);
    ASSERT_TRUE(c2 != 0);
    EXPECT_EQ(0, strcmp(c2, s3));
    EXPECT_EQ(strlen(c2), strlen(s3));
    free(c2);
	// wrong test?
    // c3 = ft_substr(s2, 20, 10);
    // ASSERT_TRUE(c3 == 0);
    // free(c3);
}

TEST(TestFtSubstr, ComplexStr) {
    char s1[] = "ghreuh gkF\tEs1eáéa24j7\v ß\\zk9jF?U+h\0x33+5krfwfeefkkkkk";
    char s2[] = "kF\tEs1eáéa24j7\v ß\\zk9jF?U+h";
    char *c1;

    c1 = ft_substr(s1, 8, 50);
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, s2));
    EXPECT_EQ(strlen(c1), strlen(s2));
    free(c1);
}

TEST(TestFtSubstr, Null) {
	char *c1;

    c1 = ft_substr(NULL, 0, 12);
    ASSERT_STREQ(c1, "");
    free(c1);
}

TEST(TestFtSubstr, StartBigger) {
	char	*str = "01234";
	size_t	size = 10;

	char	*ret = ft_substr(str, 10, size);
	ASSERT_STREQ("", ret);
	free(ret);
}