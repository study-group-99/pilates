#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtSplit, Basic0) {
    char **got = ft_split("apple,car,door,lamp", ',');
	
    EXPECT_STREQ("apple", *got) << *got;
    EXPECT_STREQ("car", *++got) << *got; 
    EXPECT_STREQ("door", *++got) << *got;
    EXPECT_STREQ("lamp", *++got) << *got;
	EXPECT_STREQ(NULL, *++got) << "Input: char **got = ft_split(\"apple,car,door,lamp\", ',');";
}

TEST(TestFtSplit, SimpleString1) {
    char **got = ft_split("apple,,,car,door,", ',');

    EXPECT_STREQ("apple", *got) << *got;
    EXPECT_STREQ("car", *++got) << *got;
    EXPECT_STREQ("door", *++got) << *got;
	EXPECT_EQ(NULL, *++got) << "Input: char **got = ft_split(\"apple,,,car,door,\", ',');";
}

TEST(TestFtSplit, SimpleString2) {
    char **got = ft_split(",apple,,,", ',');
    EXPECT_STREQ("apple", *got) << *got;

	EXPECT_STREQ(NULL, *++got) << "Input: char **got = ft_split(\",apple,,,\", ',');";
}

TEST(TestFtSplit, NoSplit) {
	char want[] = "The weather is nice.";
    char **got = ft_split(want, ',');

    EXPECT_STREQ(want, *got) << "Input: char **got = ft_split(\"The weather is nice.\", ',');";
}

TEST(TestFtSplit, ZeroString) {
    char **got = ft_split("", '.');
	EXPECT_EQ(NULL, *got) << "Input: char **got = ft_split("", '.');";
}

TEST(TestFtSplit, Basic1) {
	char **got = ft_split("ONE_TWO_THREE", '_');

    EXPECT_STREQ("ONE", *got) << "";
    EXPECT_STREQ("TWO", *++got) << "";
    EXPECT_STREQ("THREE", *++got) << "Input: ft_split(\"ONE_TWO_THREE\", '_');";
}

TEST(TestFtSplit, Basic2) {
	char **got = ft_split("O_N_E_T_W_O_T_H_R_E_E", '_');
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
	char **got = ft_split("_ONETWOTHREE", '_');
    EXPECT_STREQ("ONETWOTHREE", *got) << "Input: ft_split(\"_ONETWOTHREE\", '_');";
}

TEST(TestFtSplit, Basic4) {
    char s[] = "ONETWOTHREE_";
	char delim = '_';

	char **got = ft_split(s, delim);
    EXPECT_STREQ("ONETWOTHREE", *got) << "Input: ft_split(\"ONETWOTHREE_\", '_');";
}

TEST(TestFtSplit, Basic5) {
	char **got = ft_split("ONE_____TWO______THREE", '_');

    EXPECT_STREQ("ONE", *got) << *got;
    EXPECT_STREQ("TWO", *++got) << *got;
    EXPECT_STREQ("THREE", *++got) << "Input: ft_split(\"ONE_____TWO______THREE\", '_');";
}

TEST(TestFtSplit, Basic6) {
	char **got = ft_split("_ONE_____TWO______THREE_", '_');

    EXPECT_STREQ("ONE", *got) << *got;
    EXPECT_STREQ("TWO", *++got) << *got;
    EXPECT_STREQ("THREE", *++got) << "Input: ft_split(\"_ONE_____TWO______THREE_\", '_');";
}

TEST(TestFtSplit, Basic7) {
	char **got = ft_split("_ONETWOTHREE_", '_');

    EXPECT_STREQ("ONETWOTHREE", *got) << "Input: ft_split(\"_ONETWOTHREE_\", '_');";
}

TEST(TestFtSplit, Basic8) {
    char want[] = "U";
	char delim = '_';

	char **got = ft_split(want, delim);

    EXPECT_STREQ(want, *got) << "Input: ft_split(\"U\", '_');";
}

TEST(TestFtSplit, Advanced) {
	char **got = ft_split("_", '_');

    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"_\", '_');";
}

TEST(TestFtSplit, Advanced2) {
	char **got = ft_split("___________________", '_');

    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"___________________\", '_');";
}

TEST(TestFtSplit, Advanced3) {
    char want[] = "_";
	char delim = 0;

	char **got = ft_split(want, 0);

    EXPECT_STREQ(want, *got) << "Input: ft_split(\"_\", 0);";
}

TEST(TestFtSplit, Advanced4) {
    char want[] = "ONE_TWO_THREE";
	char delim = 0;

	char **got = ft_split(want, 0);

    EXPECT_STREQ(want, *got) << "Input: ft_split(\"ONE_THE_THREE\", 0);";
}

TEST(TestFtSplit, Advanced5) {
	char **got = ft_split("", 0);

    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"\", 0);";
}

TEST(TestFtSplit, Advanced6) {
	char **got = ft_split("", '_');

    EXPECT_STREQ(NULL, *got) << "Input: ft_split(\"\", '_');";
}

TEST(TestFtSplit, MustSegfault) {
	EXPECT_EXIT((ft_split(NULL, '_'), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_split(NULL, '_');\n";
	EXPECT_EXIT((ft_split(NULL, 0), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_split(NULL, NULL);\n";
}
