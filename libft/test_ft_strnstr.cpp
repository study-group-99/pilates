#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
#include <string.h>
#include <stdlib.h>
}

TEST(TestFtStrnstr, StrInStr) {
    char    s1[] = "rqVa63tP L66IYcM G9bzWa 5AWYtuCw4";
    char    s2[] = "cM G";
    char    *p1, *p2;
    
    p1 = ft_strnstr(s1, s2, strlen(s1));
    ASSERT_TRUE(p1 != 0);
    EXPECT_EQ(&s1[14], p1);
    EXPECT_EQ(0, strncmp(p1, s2, 4));
    p1 = ft_strnstr(s1, s2, 18);
    ASSERT_TRUE(p1 != 0);
    EXPECT_EQ(&s1[14], p1);
    EXPECT_EQ(0, strncmp(p1, s2, 4));
    p1 = ft_strnstr(s1, s2, 17);
    EXPECT_EQ(0, p1);
    p1 = ft_strnstr(s1, s2, 10);
    EXPECT_EQ(0, p1);
    p1 = ft_strnstr(s1, s2, 0);
    EXPECT_EQ(0, p1);
}

TEST(TestFtStrnstr, StrNotInStr) {
    char    s1[] = "rqVa63ttP eL6z6..IYcM G9bfzWa 5AWYtuCw4\0w";
    char    s2[] = "cM !G";
    char    s3[] = "Cw4w";
    char    s4[] = "Va63t";
    char    s5[] = "Va63";
    char    *p1;

    p1 = ft_strnstr(s1, s2, 50);
    EXPECT_EQ(0, p1);
    p1 = ft_strnstr(s1, s3, 50);
    EXPECT_EQ(0, p1);
    p1 = ft_strnstr(s1, s4, 6);
    EXPECT_EQ(0, p1);
    p1 = ft_strnstr(s5, s4, 5);
    EXPECT_EQ(0, p1);
}

TEST(TestFtStrnstr, EmptyStrs) {
    char    s1[] = "rqVa63ttP";
    char    s2[] = "";
    char    s3[] = "";
    char    s4[] = "Va63t";
    char    s5[] = "Va63";
    char    *p1;

    p1 = ft_strnstr(s1, s2, 10);
    EXPECT_EQ(s1, p1) << "1";
    p1 = ft_strnstr(s2, s1, 10);
    EXPECT_EQ(0, p1) << "2";
    // p1 = ft_strnstr(s2, s3, 10);
    // EXPECT_EQ(s2, p1) << "3";
    // p1 = ft_strnstr(s2, s3, 0);
    // EXPECT_EQ(s2, p1) << "4";
    // p1 = ft_strnstr(s5, s4, 10);
    // EXPECT_EQ(0, p1) << "5";
}

TEST(TestFtStrnstr, MixedStrs) {
    char    s[] = "seme text";
    char    s1[] = "";
    char    s2[] = "e";
    char    s3[] = "e ";
    char    s4[] = "e tex";
    char    s5[] = "Va63";
    char    *p1;

    p1 = ft_strnstr(s, s1, 9);
    EXPECT_EQ(*p1, s[0]) << "0";

    p1 = ft_strnstr(s, s2, 9);
    EXPECT_EQ(*p1, s[3]) << "1";

    p1 = ft_strnstr(s, s3, 9);
    EXPECT_EQ(*p1, s[3]) << "2";

    p1 = ft_strnstr(s, s4, 9);
    EXPECT_EQ(*p1, s[3]) << "3";

    p1 = ft_strnstr(s, s5, 9);
    EXPECT_EQ(NULL, p1) << "4";


	p1 = ft_strnstr(s2, s, 9);
    EXPECT_EQ(NULL, p1) << "1";

    p1 = ft_strnstr(s3, s, 9);
    EXPECT_EQ(NULL, p1) << "2";

    p1 = ft_strnstr(s4, s, 9);
    EXPECT_EQ(NULL, p1) << "3";

    p1 = ft_strnstr(s5, s, 9);
    EXPECT_EQ(NULL, p1) << "4";
}

TEST(TestFtStrnstr, Extra) {
	ASSERT_TRUE(NULL == ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 10));
	ASSERT_TRUE('d' == *ft_strnstr("lorem ipsum dolor sit amet", "dol", 30));
	ASSERT_STREQ(NULL, ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30));
}
