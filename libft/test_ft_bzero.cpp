#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
void bzero(void *s, size_t n);
}

TEST(TestFtBzero, SetNChar) {
    size_t  n = 4;
    char    *a1 = (char*)malloc(n * sizeof(char));
    char    *a2 = (char*)malloc(n * sizeof(char));
    
    ft_bzero(a1, n);
    bzero(a2, n);
    EXPECT_EQ(0, memcmp(a1, a2, n));
    free(a1);
    free(a2);
}

TEST(TestFtBzero, SetNthChar) {
    size_t  n = 4;
    char    *b1 = (char*)malloc(n * sizeof(char));
    *(b1) = 'a'; *(b1 + 1) = 'b'; *(b1 + 2) = 'c'; *(b1 + 3) = 'd';
    char    *b2 = (char*)malloc(n * sizeof(char));
    *(b2) = 'a'; *(b2 + 1) = 'b'; *(b2 + 2) = 'c'; *(b2 + 3) = 'd';
    
    ft_bzero(b1 + 2, 1);
    bzero(b2 + 2, 1);
    EXPECT_EQ(0, memcmp(b1, b2, n));
    free(b1);
    free(b2);
}

TEST(TestFtBzero, SetCharArr) {
    char    c1[7] = "Someth";
    char    c2[7] = "Someth";
    
    ft_bzero(c1 + 2, 2);
    bzero(c2 + 2, 2);
    EXPECT_EQ(0, memcmp(c1, c2, 7));

    ft_bzero(c1, sizeof(c1) - 1);
    bzero(c2, sizeof(c2) - 1);
    EXPECT_EQ(0, memcmp(c1, c2, 7));
}

TEST(TestFtBzero, SetIntArr) {
    int     d1[] = {10, 20, 30, 40, 50};
    int     d2[] = {10, 20, 30, 40, 50};
    int     n = sizeof(d1)/sizeof(d1[0]);
    
    bzero(d1,  sizeof(d1));
    ft_bzero(d2,  sizeof(d2));
    EXPECT_EQ(0, memcmp(d1, d2, n));
}
