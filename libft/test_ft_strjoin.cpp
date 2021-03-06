#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrjoin, SimpleString) {
	char s1[] = "Some text in string 1..";
	char s2[] = "another text in string 2 aushd";
	
	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("Some text in string 1..another text in string 2 aushd", got) << "Input: ft_strjoin(\"Some text in string 1..\", \"another text in string 2 aushd\");";
}

TEST(TestFtStrjoin, BothZeroString) {
	char s1[] = "";
	char s2[] = "";

	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("", got) << "Input: ft_strjoin(\"\", \"\");";
}

TEST(TestFtStrjoin, FirstZeroString) {
	char s1[] = "";
	char s2[] = "another text in string 2 aushd";

	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("another text in string 2 aushd", got)  << "Input: ft_strjoin(\"\", \"another text in string 2 aushd\");";
}

TEST(TestFtStrjoin, SecondZeroString) {
	char s1[] = "Some text in string 1..";
	char s2[] = "";

	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("Some text in string 1..", got) << "Input: ft_strjoin(\"Some text in string 1..\", \"\");";
}

TEST(TestFtStrjoin, Nested) {
	char s1[] = "my favorite animal is";
	char s2[] = " ";
	char s3[] = "the dinosaur";

	char *got = ft_strjoin(ft_strjoin(s1, s2), s3);
	EXPECT_STREQ("my favorite animal is the dinosaur", got) << "Input: 	char s1[] = \"my favorite animal is\"; char s2[] = " "; char s3[] = \"the dinosaur\"; char *got = ft_strjoin(ft_strjoin(s1, s2), s3);";
	}

TEST(TestFtStrjoin, Free) {
	char s1[] = "my favorite animal is";
	char s2[] = " ";
	char s3[] = "the dinosaur";

	char *tmp = ft_strjoin(s1, s2);
	char *got = ft_strjoin(tmp, s3);
	free(tmp);
	EXPECT_STREQ("my favorite animal is the dinosaur", got) << "Input: 	char s1[] = \"my favorite animal is\"; char s2[] = " "; char s3[] = \"the dinosaur\"; char *tmp = ft_strjoin(s1, s2); char *got = ft_strjoin(tmp, s3); free(tmp);";
}

TEST(TestFtStrjoin, Overlap) {
	char want[] = "my favorite animal is ";
	char *s = want + 20;

	char *got = ft_strjoin(s, want);
	EXPECT_STREQ("s my favorite animal is ", got) << "Input: char want[] = \"my favorite animal is \"; char *s = want + 20; ft_strjoin(s, want);";
}
