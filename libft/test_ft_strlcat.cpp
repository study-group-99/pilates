#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrlcat, AllCharacters) {
	char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
	EXPECT_EQ(strlen(first), 8);

    r = ft_strlcat(first,last,(strlen(first) + strlen(last)));

	EXPECT_EQ(strlen(first) + 1, r);
	ASSERT_STREQ(first, "This is a potentially long strin") << first;
}
