#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrtrim, SimpleTrim) {
    char s1[] = "This text is long";
    char *c1;

    c1 = ft_strtrim(s1, " ighlnoTs");
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, "text"));
    free(c1);
    c1 = ft_strtrim(s1, "This ");
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, "text is long"));
    free(c1);
    c1 = ft_strtrim(s1, "long ");
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, "This text is"));
    free(c1);
}

TEST(TestFtStrtrim, TrimZeroStr) {
    char s1[] = "";
    char *c1;

    c1 = ft_strtrim(s1, "abcd ");
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, ""));
    free(c1);
}

TEST(TestFtStrtrim, TrimEverything) {
    char s1[] = "This text is long";
    char *c1;

    c1 = ft_strtrim(s1, " eighlnotTsx");
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, ""));
    free(c1);
}

TEST(TestFtStrtrim, TrimNothing) {
    char s1[] = "This text is long";
    char *c1;

    c1 = ft_strtrim(s1, " abd");
    ASSERT_TRUE(c1 != 0);
    EXPECT_EQ(0, strcmp(c1, "This text is long"));
    free(c1);
}