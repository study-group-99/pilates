#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrdup, SimpleStr) {
    char s1[] = "Test";
    char s2[] = "ThislkjeO4jml5knlnlt";
    char *c1, *c2;

    c1 = ft_strdup(s1);
    ASSERT_TRUE(c1 != 0);
    EXPECT_NE(c1, s1);
    EXPECT_EQ(0, strcmp(c1, s1));
    EXPECT_EQ(strlen(s1), strlen(c1));
    free(c1);
    c2 = ft_strdup(s2);
    EXPECT_NE(c2, s2);
    EXPECT_EQ(0, strcmp(c2, s2));
    EXPECT_EQ(strlen(s2), strlen(c2));
    free(c2);
}

TEST(TestFtStrdup, ZeroStr) {
    char s1[] = "";
    char *c1;

    c1 = ft_strdup(s1);
    ASSERT_TRUE(c1 != 0);
    EXPECT_NE(c1, s1);
    EXPECT_EQ(0, strcmp(c1,s1));
    EXPECT_EQ(strlen(s1), strlen(c1));
    free(c1);
}

TEST(TestFtStrdup, CopyUntilTerminator) {
    char s1[] = "ThislkjeO4jml5\0knlnlt";
    char *c1, *c2;

    c1 = ft_strdup(s1);
    c2 = strdup(s1);
    ASSERT_TRUE(c1 != 0);
    EXPECT_NE(c1, s1);
    EXPECT_EQ(0, strcmp(c1, c2));
    EXPECT_EQ(strlen(c1), strlen(c2));
    EXPECT_EQ(0, strcmp(c1, s1));
    EXPECT_TRUE(strlen(c1) < 16);
    free(c1);
    free(c2);
}

TEST(TestFtStrdup, ComplexStr) {
    char s1[] = "ghreuh gkF\tEs1eáéa24j7\v ß\\zk9jF?U+h\0x33+5krfwfeefkkkkk";
    char *c1, *c2;

    c1 = ft_strdup(s1);
    c2 = strdup(s1);
    ASSERT_TRUE(c1 != 0);
    EXPECT_NE(c1, s1);
    EXPECT_EQ(0, strcmp(c1, c2));
    EXPECT_EQ(strlen(c1), strlen(c2));
    EXPECT_EQ(0, strcmp(c1, s1));
    free(c1);
    free(c2);
}
