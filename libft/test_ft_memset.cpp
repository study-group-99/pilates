#include <gtest/gtest.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemset, NChar) {
    char *want = (char*)malloc(4 * sizeof(char));
    char *got = (char*)malloc(4 * sizeof(char));
    
 	memset(want, 'a', 4); ft_memset(got, 'a', 4);

    EXPECT_STREQ(want, got) << "Input: char *got = (char*)malloc(4 * sizeof(char)); ft_memset(got, 'a', 4);";
}

TEST(TestFtMemset, NCharReturn) {
    char *s1 = (char*)malloc(4 * sizeof(char));
    char *s2 = (char*)malloc(4 * sizeof(char));

    void *want = memset(s1, 'a', 4);
    void *got = ft_memset(s2, 'a', 4);

    EXPECT_STREQ((char *)want, (char *)got) << "Input: char    *s2 = (char*)malloc(4 * sizeof(char)); void *got = ft_memset(s2, 'a', 4);";
}

TEST(TestFtMemset, NthChar) {
    char *want = (char*)malloc(4 * sizeof(char));
    *(want) = 'a'; *(want + 1) = 'b'; *(want + 2) = 'c'; *(want + 3) = 'd';

    char *got = (char*)malloc(4 * sizeof(char));
    *(got) = 'a'; *(got + 1) = 'b'; *(got + 2) = 'c'; *(got + 3) = 'd';
    
    memset(want + 2, '$', 1); ft_memset(got + 2, '$', 1);

    EXPECT_STREQ(want, got) << "Input: char *got = (char*)malloc(4 * sizeof(char)); *(got) = 'a'; *(got + 1) = 'b'; *(got + 2) = 'c'; *(got + 3) = 'd'; ft_memset(got + 2, '$', 1);";
}

TEST(TestFtMemset, NthCharReturn) {
    char *s1 = (char*)malloc(4 * sizeof(char));
    *(s1) = 'a'; *(s1 + 1) = 'b'; *(s1 + 2) = 'c'; *(s1 + 3) = 'd';

    char *s2 = (char*)malloc(4 * sizeof(char));
    *(s2) = 'a'; *(s2 + 1) = 'b'; *(s2 + 2) = 'c'; *(s2 + 3) = 'd';
    
    void *want = memset(s1 + 2, '$', 1); 
	void *got = ft_memset(s2 + 2, '$', 1);

    EXPECT_STREQ((char *)want, (char *)got) << "Input: char *s2 = (char*)malloc(4 * sizeof(char)); *(s2) = 'a'; *(s2 + 1) = 'b'; *(s2 + 2) = 'c'; *(s2 + 3) = 'd'; void *got = ft_memset(s2 + 2, '$', 1);";
}

TEST(TestFtBzero, CharArray) {
    char want[7] = "Someth";
    char got[7] = "Someth";
    
    memset(want + 2, 'a', 2); ft_memset(got + 2, 'a', 2);
    
    EXPECT_STREQ(want, got) << "Input: char got[7] = \"Someth\"; ft_memset(got + 2, 'a', 2);";

	memset(want, '-', sizeof(got) - 1); ft_memset(got, '-', sizeof(want) - 1);

    EXPECT_STREQ(want, got) << "Input: char got[7] = \"Someth\"; ft_memset(got, '-', sizeof(want) - 1);";
}

TEST(TestFtBzero, IntArray) {
    int s1[] = {10, 20, 30, 40, 50};
    int s2[] = {10, 20, 30, 40, 50};
    
	void *want = memset(s1, 110, sizeof(s1));
    void *got = ft_memset(s2, 110, sizeof(s2));

    EXPECT_STREQ((char *)want, (char *)got) << "Input: int s2[] = {10, 20, 30, 40, 50}; void *got = ft_memset(s2, 110, sizeof(s2));";
}

TEST(TestFtBzero, Unsigned) {
	const int size = 22;
	char want[32], got[32];
	memset(want, 'B', 10);
	memset(got, 'B', 10);

	memset(want, '\200', size); ft_memset(got, '\200', size);

	EXPECT_STREQ(want, got) << "Input: char got[32]; memset(got, 'B', 10); ft_memset(got, '\\200', 22);";
}

TEST(TestFtBzero, Zero) {
	char want[10], got[10];
	memset(want, 0, sizeof(want));
	memset(got, 0, sizeof(got));

	memset(want, '\xff', 0); ft_memset(got, '\xff', 0);

	EXPECT_STREQ(want, got);
}
