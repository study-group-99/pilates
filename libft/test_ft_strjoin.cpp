#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrjoin, SimpleString) {
	char s1[] = "Some text in string 1..";
	char s2[] = "another text in string 2 aushd";
	
	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("Some text in string 1..another text in string 2 aushd", got);
}

TEST(TestFtStrjoin, BothZeroString) {
	char s1[] = "";
	char s2[] = "";

	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("", got);
}

TEST(TestFtStrjoin, FirstZeroString) {
	char s1[] = "";
	char s2[] = "another text in string 2 aushd";

	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("another text in string 2 aushd", got);
}

TEST(TestFtStrjoin, SecondZeroString) {
	char s1[] = "Some text in string 1..";
	char s2[] = "";

	char *got = ft_strjoin(s1, s2);
	EXPECT_STREQ("Some text in string 1..", got);
}

TEST(TestFtStrjoin, Nested) {
	char s1[] = "my favorite animal is";
	char s2[] = " ";
	char s3[] = "the dinosaur";

	char *got = ft_strjoin(ft_strjoin(s1, s2), s3);
	EXPECT_STREQ("my favorite animal is the dinosaur", got);
}

TEST(TestFtStrjoin, Free) {
	char s1[] = "my favorite animal is";
	char s2[] = " ";
	char s3[] = "the dinosaur";

	char *tmp = ft_strjoin(s1, s2);
	char *got = ft_strjoin(tmp, s3);
	free(tmp);
	EXPECT_STREQ("my favorite animal is the dinosaur", got);
}

TEST(TestFtStrjoin, Overlap) {
	char want[] = "my favorite animal is ";
	char *s = want + 20;

	char *got = ft_strjoin(s, want);
	EXPECT_STREQ("s my favorite animal is ", got);
}

TEST(TestFtStrjoin, MustSegfault) {
	EXPECT_EXIT((ft_strjoin(NULL, "where is my "), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strjoin(NULL, \"where is my \");\n";
	EXPECT_EXIT((ft_strjoin("where is my ", NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strjoin(\"where is my \", NULL);\n";
	EXPECT_EXIT((ft_strjoin(NULL, NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strjoin(NULL, NULL);\n";
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
