#include <gtest/gtest.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemset, SetNChar) {
    size_t  n = 4;
    char    *a1 = (char*)malloc(n * sizeof(char));
    char    *a2 = (char*)malloc(n * sizeof(char));
    void    *b1, *b2;
    
    b1 = ft_memset(a1, 'a', n);
    b2 = memset(a2, 'a', n);
    ASSERT_TRUE(b1 != 0);
    EXPECT_EQ(a1, b1);
    EXPECT_EQ(0, memcmp(a1, a2, n));
    free(a1);
    free(a2);
}

TEST(TestFtMemset, SetNthChar) {
    size_t  n = 4;
    void    *a1, *a2;
    char    *b1 = (char*)malloc(n * sizeof(char));
    *(b1) = 'a'; *(b1 + 1) = 'b'; *(b1 + 2) = 'c'; *(b1 + 3) = 'd';
    char    *b2 = (char*)malloc(n * sizeof(char));
    *(b2) = 'a'; *(b2 + 1) = 'b'; *(b2 + 2) = 'c'; *(b2 + 3) = 'd';
    
    a1 = ft_memset(b1 + 2, '$', 1);
    a2 = memset(b2 + 2, '$', 1);
    ASSERT_TRUE(a1 != 0);
    EXPECT_EQ(a1, b1 + 2);
    EXPECT_EQ(0, memcmp(b1, b2, n));
    free(b1);
    free(b2);
}

TEST(TestFtBzero, SetCharArr) {
    char    c1[7] = "Someth";
    char    c2[7] = "Someth";
    
    ft_memset(c1 + 2, 'a', 2);
    memset(c2 + 2, 'a', 2);
    EXPECT_EQ(0, memcmp(c1, c2, 7));

    ft_memset(c1, '-', sizeof(c1) - 1);
    memset(c2, '-', sizeof(c2) - 1);
    EXPECT_EQ(0, memcmp(c1, c2, 7));
}

TEST(TestFtBzero, SetIntArr) {
    int     d1[] = {10, 20, 30, 40, 50};
    int     d2[] = {10, 20, 30, 40, 50};
    void    *a1, *a2;
    int     n = sizeof(d1)/sizeof(d1[0]);
    
    a1 = ft_memset(d1, 110, sizeof(d1));
    a2 = memset(d2, 110, sizeof(d2));
    ASSERT_TRUE(a1 != 0);
    EXPECT_EQ(0, memcmp(a1, a2, n));
}
