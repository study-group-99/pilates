#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtCalloc, Null) {
	char *got = (char *)ft_calloc(4, 20);
	char *want = (char *)calloc(4, 20);

	EXPECT_TRUE(got != NULL) << "Input: char *got = (char *)ft_calloc(4, 20);\n";
	EXPECT_STREQ(want, got) << "Input: char *got = (char *)ft_calloc(4, 20);\n";
}

TEST(TestFtCalloc, Zero) {
	void *got = (char *)ft_calloc(0, 0);

	EXPECT_TRUE(got != NULL) << "Input: char *got = (char *)ft_calloc(0, 0);\n";
}

TEST(TestFtCalloc, Basic) {
	int	size = 8539;
	void *got = ft_calloc(size, sizeof(int));
	void *want = calloc(size, sizeof(int));

	EXPECT_STREQ((const char*)got, (const char*)want) << "Input: void *got = ft_calloc(8539, sizeof(int));\n";
}

TEST(TestFtCalloc, Size) {
    int got = 42 * 3;
    int want = 42 * 3;

	ft_calloc(got, sizeof(char)); calloc(want, sizeof(char));

	EXPECT_EQ(got * sizeof(char), want * sizeof(char)) << "Input: int got = 42 * 3; ft_calloc(got, sizeof(char));\n";
}
