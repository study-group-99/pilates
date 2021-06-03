#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtSplit, BasicSplit) {
    char s1[] = "apple,car,door,lamp";
    char **c1;
	char delim;

	delim = ',';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0);
    ASSERT_STREQ("apple", c1[0]);
    ASSERT_STREQ("car", c1[1]);
    ASSERT_STREQ("door", c1[2]);
    ASSERT_STREQ("lamp", c1[3]);
	EXPECT_EQ(0, c1[4]);
    free(c1[0]);
    free(c1[1]);
    free(c1[2]);
    free(c1[3]);
	free(c1);
}

TEST(TestFtSplit, BasicSplitSpace) {
    char s1[] = "      split       this for   me  !       ";
    char **c1;
	char delim;

	delim = ' ';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0);
    ASSERT_STREQ("split", c1[0]);
    ASSERT_STREQ("this", c1[1]);
    ASSERT_STREQ("for", c1[2]);
    ASSERT_STREQ("me", c1[3]);
    ASSERT_STREQ("!", c1[4]);
    ASSERT_STREQ(NULL, c1[5]);
	free(c1);
}

TEST(TestFtSplit, BasicSplitSpace2) {
    char s1[] = "split  ||this|for|me|||||!|";
    char **c1;
	char delim;

	delim = '|';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0);
    ASSERT_STREQ("split  ", c1[0]);
    ASSERT_STREQ("this", c1[1]);
    ASSERT_STREQ("for", c1[2]);
    ASSERT_STREQ("me", c1[3]);
    ASSERT_STREQ("!", c1[4]);
    ASSERT_STREQ(NULL, c1[5]);
	free(c1);
}

TEST(TestFtSplit, AdvancedSplitSpace) {
    char s1[] = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
    char **c1;
	char delim;

	delim = ' ';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0);
    ASSERT_STREQ("lorem", c1[0]);
    ASSERT_STREQ("ipsum", c1[1]);
    ASSERT_STREQ("dolor", c1[2]);
    ASSERT_STREQ("sit", c1[3]);
    ASSERT_STREQ("amet,", c1[4]);
	free(c1);
}

TEST(TestFtSplit, BasicSplitZ) {
    char s1[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
    char **c1;
	char delim;

	delim = 'z';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0);
    ASSERT_STREQ(s1, c1[0]);
    ASSERT_STREQ(NULL, c1[1]);
	free(c1);
}

TEST(TestFtSplit, SimpleStr) {
    char s1[] = "apple,,,car,door,";
    char s2[] = ",apple,,,";
    char **c1;
	char delim;

	delim = ',';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0) << "0";
    ASSERT_STREQ("apple", c1[0]) << "1";
    ASSERT_STREQ("car", c1[1]) << "2";
    ASSERT_STREQ("door", c1[2]) << "3";
    free(c1);
	c1 = ft_split(s2, delim);
    ASSERT_TRUE(c1 != 0) << "4";
	free(c1);
}

TEST(TestFtSplit, NoSplit) {
    char s1[] = "The weather is nice.";
    char **c1;
	char delim;

	delim = ',';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1[0], s1));
	EXPECT_EQ(0, c1[1]);
    free(c1[0]);
	free(c1);
}

TEST(TestFtSplit, ZeroStr) {
    char s1[] = "";
    char **c1;
	char delim;

	delim = '.';
    c1 = ft_split(s1, delim);
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(NULL, c1[0]);
	free(c1);
}


TEST(TestFtZeroAlt, Null) {
	char s1[] = "";
	char delim = 0;

	char	**expected = ft_split(s1, delim);
	EXPECT_EQ(NULL, expected[0]);
}

TEST(TestFtZeroAlt2, Null) {
	char s1[] = "ONE_TWO_THREE";
	char delim = 0;

	char	**expected = ft_split(s1, delim);
	EXPECT_EQ(*s1, *expected[0]) << expected[0];
	EXPECT_EQ(NULL, expected[1]) << expected[1];
}
