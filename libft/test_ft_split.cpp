#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtSplit, Basic) {
    char *s = "ONE_TWO_THREE";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONE", *got) << "";
    EXPECT_STREQ("TWO", *++got) << "";
    EXPECT_STREQ("THREE", *++got) << "Input: ft_split(\"ONE_TWO_THREE\", '_');";
}

TEST(TestFtSplit, Basic2) {
    char *s = "O_N_E_T_W_O_T_H_R_E_E";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("O", *got) << "";
    EXPECT_STREQ("N", *++got) << *got;
    EXPECT_STREQ("E", *++got) << *got;
    EXPECT_STREQ("T", *++got) << *got;
    EXPECT_STREQ("W", *++got) << *got;
    EXPECT_STREQ("O", *++got) << *got;
    EXPECT_STREQ("T", *++got) << *got;
    EXPECT_STREQ("H", *++got) << *got;
    EXPECT_STREQ("R", *++got) << *got;
    EXPECT_STREQ("E", *++got) << *got;
    EXPECT_STREQ("E", *++got) << "Input: ft_split(\"O_N_E_T_W_O_T_H_R_E_E\", '_');";
}

TEST(TestFtSplit, Basic3) {
    char *s = "_ONETWOTHREE";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONETWOTHREE", *got) << "Input: ft_split(\"_ONETWOTHREE\", '_');";
}

TEST(TestFtSplit, Basic4) {
    char *s = "ONETWOTHREE_";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONETWOTHREE", *got) << "Input: ft_split(\"ONETWOTHREE_\", '_');";
}

TEST(TestFtSplit, Basic5) {
    char *s = "ONE_____TWO______THREE";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONE", *got) << *got;
    EXPECT_STREQ("TWO", *++got) << *got;
    EXPECT_STREQ("THREE", *++got) << "Input: ft_split(\"ONE_____TWO______THREE\", '_');";
}

TEST(TestFtSplit, Basic6) {
    char *s = "_ONE_____TWO______THREE_";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONE", *got) << *got;
    EXPECT_STREQ("TWO", *++got) << *got;
    EXPECT_STREQ("THREE", *++got) << "Input: ft_split(\"_ONE_____TWO______THREE_\", '_');";
}

TEST(TestFtSplit, Basic7) {
    char *s = "_ONETWOTHREE_";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONETWOTHREE", *got) << "Input: ft_split(\"_ONETWOTHREE_\", '_');";
}

TEST(TestFtSplit, Basic8) {
    char *s = "U";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("U", *got) << "Input: ft_split(\"U\", '_');";
}

TEST(TestFtSplit, Advanced) {
    char *s = "_";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"_\", '_');";
}

TEST(TestFtSplit, Advanced2) {
    char *s = "___________________";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"___________________\", '_');";
}

TEST(TestFtSplit, Advanced3) {
    char *s = "_";
	char delim = 0;

	char **got = ft_split(s, delim);
    EXPECT_STREQ("_", *got) << "Input: ft_split(\"_\", 0);";
}

TEST(TestFtSplit, Advanced4) {
    char *s = "ONE_TWO_THREE";
	char delim = 0;

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONE_TWO_THREE", *got) << "Input: ft_split(\"ONE_THE_THREE\", 0);";
}

TEST(TestFtSplit, Advanced5) {
    char *s = "";
	char delim = 0;

	char **got = ft_split(s, delim);
    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"\", 0);";
}

TEST(TestFtSplit, Advanced6) {
    char *s = "";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"\", '_');";
}

TEST(TestFtSplit, MustSegfault) {
	EXPECT_EXIT((ft_split(NULL, '_'), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_split(NULL, '_');\n";
	EXPECT_EXIT((ft_split(NULL, NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_split(NULL, NULL);\n";
}
