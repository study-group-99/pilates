#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtCalloc, SetElementsChar) {
    size_t  n = 4;
    char    *a1 = (char*)ft_calloc(n, sizeof(char));
    char    *a2 = (char*)calloc(n, sizeof(char));
    char    s1[] = "Hi!\0";
    
    ASSERT_TRUE(a1 != 0);
    
    memcpy(a1, s1, n);
    memcpy(a2, s1, n);
    EXPECT_EQ(0, memcmp(a1, a2, n));
    free(a1);
}

TEST(TestFtCalloc, SetElementsInt) {
    size_t  n = 5;
    int isrc1[] = {10, 20, 30, 40, 50};
    int isrc2[] = {10, 20, 30, 40, 50};
    int *idest1 = (int*)ft_calloc(n, sizeof(int));
    int *idest2 = (int*)ft_calloc(n, sizeof(int));

    memcpy(idest1, isrc1, n*sizeof(int));
    ft_memcpy(idest2, isrc2, n*sizeof(int));
    EXPECT_EQ(0, memcmp(idest1, idest2, n*sizeof(int)));
    free(idest1);
    free(idest2);
}

TEST(TestFtCalloc, BitsSetZero) {
    size_t  n = 4;
    char    *a1 = (char*)ft_calloc(n, sizeof(char));

    ASSERT_TRUE(a1 != 0);
    EXPECT_EQ(0, *a1);
    EXPECT_EQ(0, *(a1 + 1));
    EXPECT_EQ(0, *(a1 + 2));
    EXPECT_EQ(0, *(a1 + 3));
    free(a1);
}
