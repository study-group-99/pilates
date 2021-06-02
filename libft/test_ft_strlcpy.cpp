#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrlcpy, AllCharacters) {
	char src[] = "Hello there, Venus";
    char dst[19];

	size_t r = ft_strlcpy(dst, src, ft_strlen(src));
    EXPECT_EQ(18, r);
    EXPECT_EQ(*src, *dst) << src;
}

TEST(TestFtStrlcpy, SomeCharacters) {
    const char src[] = "Test123";
	char dst[] = {};

    EXPECT_EQ(7, ft_strlcpy(dst, src, 2));
    EXPECT_EQ('\0', dst[1]);
}

TEST(TestFtStrlcpy, NoCharacters) {
    const char yo[] = {};
	char dst[] = {};

    EXPECT_EQ(0, ft_strlcpy(dst, yo, 0));
    EXPECT_EQ(*yo, *dst);
}
