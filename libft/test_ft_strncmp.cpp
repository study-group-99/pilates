#include <gtest/gtest.h>
#include <string.h>
#include <stdio.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrncmp, CompEmpty) {
    char *s1;
    char *s2;
    
    int want = strncmp(s1, s2, 0);
    int got = ft_strncmp(s1, s2, 0);
    EXPECT_TRUE(want == got) << "Input: char *s1; char *s2; ft_strncmp(s1, s2, 0);";
}

TEST(TestFtStrncmp, Empty) {
    char s1[] = "";
    char s2[] = "";
    
    int want = strncmp(s1, s2, 0);
    int got = ft_strncmp(s1, s2, 0);
    EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"\", \"\", 0);";
}

TEST(TestFtStrncmp, EmptyDest) {
    char s1[] = "";
    char s2[] = "test";
    
    int want = strncmp(s1, s2, 0);
    int got = ft_strncmp(s1, s2, 0);
    EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"\", \"test\", 0);";
}

TEST(TestFtStrncmp, EmptySource) {
    char s1[] = "test";
    char s2[] = "";

    int want = strncmp(s1, s2, 0);
    int got = ft_strncmp(s1, s2, 0);
    EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"test\", \"\", 0);";
}

TEST(TestFtStrncmp, CompStr) {
    char s1[8] = "Somethi";
    char s2[8] = "Sometht";

    int want = strncmp(s1, s2, 8);
    int got = ft_strncmp(s1, s2, 8);
    EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"Somethi\", \"Somethi\", 8);";
}

TEST(TestFtStrncmp, CompLongerStr) {
    char s1[8] = "Sometht";
    char s2[11] = "Somethting";

    int want = strncmp(s1, s2, 10);
    int got = ft_strncmp(s1, s2, 10);
    EXPECT_TRUE(want == got) << "Input: char s1[8] = \"Sometht\"; char s2[11] = \"Somethting\"; ft_strncmp(s1, s2, 10);";
}

TEST(TestFtStrncmp, CompExtra) {
    char s1[] = "Tex_klkj;%,m\tl!3,t1";
    char s2[] = "Tex_klkj;%,m\tl!3,t1";
    
    int want = strncmp(s1, s2, 15);
    int got = ft_strncmp(s1, s2, 15);
    EXPECT_TRUE(want == got) << "Input: char s1[] = \"Tex_klkj;%,m\\tl!3,t1\"; char s2[] = \"Tex_klkj;%,m\\tl!3,t1\"; ft_strncmp(s1, s2, 15);";
}

TEST(TestFtStrncmp, UnsignedChar) {
	char s1[] = "\200";
	char s2[] = "\0";

	int want = strncmp(s1, s2, 1);
	int got = ft_strncmp(s1, s2, 1);
	EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"\\200\", \"\\0\", 1);";
}

TEST(TestFtStrncmp, StopAtZero) {
	char s1[] = "atoms\0\0\0\0";
	char s2[] = "atoms\0abc";
	size_t  size = 8;

	int want = strncmp(s1, s2, 1);
	int got = ft_strncmp(s1, s2, 1);
	EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"atoms\\0\\0\\0\\0\", \"atoms\\0abc\", 1);";
}

TEST(TestFtStrncmp, NonAscii) {
	char s1[] = "\x12\xff\x65\x12\xbd\xde\xad";
	char s2[] = "\x12\x02";
	size_t size = 6;

	int want = strncmp(s1, s2, size);
	int got = ft_strncmp(s1, s2, size);
	EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"\\x12\\xff\\x65\\x12\\xbd\\xde\\xad\", \"\\x12\\x02\", 6);";
}

TEST(TestFtStrncmp, Contained) {
	char s1[] = "abcdef";
	char s2[] = "abcdefghijklmnop";
	size_t size = 6;

	int want = strncmp(s1, s2, size);
	int got = ft_strncmp(s1, s2, size);
	EXPECT_TRUE(want == got) << "Input: ft_strncmp(\"abcdef\", \"abcdefghijklmnop\", 6);";
}
