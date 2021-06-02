#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrncmp, CompEmpty) {
    size_t  n = 0;
    char    *c1;
    char    *c2;
    int     res1;
    int     res2;
    
    res1 = memcmp(c1, c2, 0);
    res2 = ft_memcmp(c1, c2, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c2, c1, 0);
    res2 = ft_memcmp(c2, c1, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
}

TEST(TestFtMemcmp, CompCharArr) {
    size_t  n = 4;
    char    c1[8] = "Somethi";
    char    c2[8] = "Sometht";
    int     res1;
    int     res2;
    
    res1 = memcmp(c1, c2, 8);
    res2 = ft_memcmp(c1, c2, 8);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c2, c1, 8);
    res2 = ft_memcmp(c2, c1, 8);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c1, c2, 7);
    res2 = ft_memcmp(c1, c2, 7);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c2, c1, 7);
    res2 = ft_memcmp(c2, c1, 7);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c1, c2, 0);
    res2 = ft_memcmp(c1, c2, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c2, c1, 0);
    res2 = ft_memcmp(c2, c1, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
}

TEST(TestFtMemcmp, CompIntArr) {
    int c1[] = {10, 20, 30, 40, 50};
    int c2[] = {10, 20, 30, 40, 50};
    int n = sizeof(c1)/sizeof(c1[0]);
    int res1;
    int res2;

    res1 = memcmp(c2, c1, n);
    res2 = ft_memcmp(c2, c1, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    c1[1] = 0;
    res1 = memcmp(c2, c1, n);
    res2 = ft_memcmp(c2, c1, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
}

TEST(TestFtMemcmp, CompInt) {
    int c1 = -12345;
    int c2 = -12345;
    int n = sizeof(int);
    int res1;
    int res2;
    
    res1 = memcmp(&c2, &c1, n);
    res2 = ft_memcmp(&c2, &c1, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(&c1, &c2, n);
    res2 = ft_memcmp(&c1, &c2, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    
    c1 = 155;
    c2 = -35;
    res1 = memcmp(&c2, &c1, n);
    res2 = ft_memcmp(&c2, &c1, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(&c1, &c2, n);
    res2 = ft_memcmp(&c1, &c2, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
}

TEST(TestFtMemcmp, CompCharInt) {
    int     n = 6;
    int     c1[] = {104, 101, 108, 108, 111};
    char    c2[n] = "hello";
    int     res1;
    int     res2;
    
    res1 = memcmp(c1, c2, n);
    res2 = ft_memcmp(c1, c2, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c2, c1, n);
    res2 = ft_memcmp(c2, c1, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
 
    n = sizeof(c1)/sizeof(c1[0]);
    res1 = memcmp(c1, c2, n);
    res2 = ft_memcmp(c1, c2, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = memcmp(c2, c1, n);
    res2 = ft_memcmp(c2, c1, n);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
}
