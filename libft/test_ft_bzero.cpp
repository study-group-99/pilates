#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtBzero, SetNChar) {
    char got[4];
    char want[4];

    ft_bzero(got, 4); bzero(want, 4);

    EXPECT_STREQ(want, got) << "Input: char got[4]; ft_bzero(got, 4);\n";
}

TEST(TestFtBzero, SetNthChar) {
	char got[] = {'a', 'b', 'c', 'd'};
	char want[] = {'a', 'b', 'c', 'd'};

    ft_bzero(got, 1); bzero(want, 1);

	EXPECT_STREQ(want, got) << "Input: char got[] = {'a', 'b', 'c', 'd'}; ft_bzero(got, 1);\n";
}

TEST(TestFtBzero, SetCharArr) {
    char got[7] = "Someth";
    char want[7] = "Someth";

    ft_bzero(got + 2, 2); bzero(want + 2, 2);

    EXPECT_STREQ(want, got) << "Input: char got[7] = \"Someth\"; ft_bzero(got + 2, 2);\n";
}

TEST(TestFtBzero, SetIntArr) {
    char got[] = {10, 20, 30, 40, 50};
    char want[] = {10, 20, 30, 40, 50};

	ft_bzero(got, sizeof(got)); bzero(want,  sizeof(want));

    EXPECT_STREQ(want, got) << "Input: int got[] = {10, 20, 30, 40, 50}; ft_bzero(got,  sizeof(s1));\n";
}
