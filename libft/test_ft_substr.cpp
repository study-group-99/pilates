#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtSubstr, SimpleStr1) {
    char *got = ft_substr("this is a string", 2, 5);
    ASSERT_STREQ("is is", got) << "Input: char *got = ft_substr(\"this is a string\", 2, 5);";
}

TEST(TestFtSubstr, SimpleStr2) {
    char *got = ft_substr("this is a string", 10, 5);
    ASSERT_STREQ("strin", got) << "Input: char *got = ft_substr(\"this is a string\", 10, 5);";
}

TEST(TestFtSubstr, EmptyStr) {
    char *got = ft_substr("", 0, 0);
    ASSERT_STREQ("", got) << "Input: char *got = ft_substr(\"\", 0, 0);";
}

TEST(TestFtSubstr, EmptyStr2) {
	char *got = ft_substr("", 1, 1);
    ASSERT_STREQ("", got) << "Input: char *got = ft_substr(\"\", 1, 1);";
}

TEST(TestFtSubstr, EmptyStr3) {
    char *got = ft_substr("", 0, 3);
    EXPECT_STREQ("", got) << "Input: char *got = ft_substr(\"\", 0, 3);";
}

TEST(TestFtSubstr, EmptyStr4) {
    char *got = ft_substr("ThislkjeO4jml5knlnlt", 10, 0);
    EXPECT_STREQ("", got) << "Input: char *got = ft_substr(\"ThislkjeO4jml5knlnlt\", 10, 0);";
}

TEST(TestFtSubstr, CopyUntilTerminator) {
    char *got = ft_substr("ThislkjeO4jml5\0knlnlt", 0, 50);
    EXPECT_STREQ("ThislkjeO4jml5", got) << "Input: char *got = ft_substr(\"ThislkjeO4jml5\\0knlnlt\", 0, 50);";
}

TEST(TestFtSubstr, CopyUntilTerminator2) {;
    char *got = ft_substr("ThislkjeO4jml5", 14, 10);
    EXPECT_STREQ("", got) << "Input: char *got = ft_substr(\"ThislkjeO4jml5\", 14, 10);";
}

TEST(TestFtSubstr, ComplexStr) {
    char *got = ft_substr("ghreuh gkF\tEs1eáéa24j7\v ß\\zk9jF?U+h\0x33+5krfwfeefkkkkk", 8, 50);
    EXPECT_STREQ("kF\tEs1eáéa24j7\v ß\\zk9jF?U+h", got) << "Input: char *got = ft_substr(\"ghreuh gkF\\tEs1eáéa24j7\\v ß\\zk9jF?U+h\\0x33+5krfwfeefkkkkk\", 8, 50);";
}

TEST(TestFtSubstr, Null) {
    char *got = ft_substr(NULL, 0, 12);
    ASSERT_STREQ("", got) << "Input: char *got = ft_substr(NULL, 0, 12);";
}

TEST(TestFtSubstr, StartBigger) {
	char *got = ft_substr("01234", 10, 10);
	ASSERT_STREQ("", got) << "Input: char *got = ft_substr(\"01234\", 10, 10);";
}

TEST(TestFtSubstr, Basic) {
	char *got = ft_substr("i just want this part #############", 0, 22);
	EXPECT_STREQ("i just want this part ", got) << "Input: char *got = ft_substr(\"i just want this part #############\", 0, 22);";
}

TEST(TestFtSubstr, Basic2) {
	char *got = ft_substr("i just want this part #############", 5, 20);
	EXPECT_STREQ("t want this part ###", got) << "Input: char *got = ft_substr(\"i just want this part #############\", 5, 20);";
}

TEST(TestFtSubstr, Basic3) {
	char want[] = "all of this !";
	size_t size = strlen(want);

	char *got = ft_substr(want, 0, size);
	EXPECT_STREQ(want, got) << "Input: char *got = ft_substr(\"all of this !\", 0, 14);";
}

TEST(TestFtSubstr, StartBiggerThanSize) {
	char *got = ft_substr("01234", 10, 10);
	EXPECT_STREQ("", got) << "Input: char *got = ft_substr(\"01234\", 10, 10);";
}
