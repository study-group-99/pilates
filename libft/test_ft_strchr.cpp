#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrchr, CharInString) {
    char s[] = "This is Some\ntext.\0    ";

    char *want = strchr(s, 'o');
    char *got = ft_strchr(s, 'o');
    EXPECT_EQ(want, got);

    want = strchr(s, 'x');
    got = ft_strchr(s, 'x');
    EXPECT_EQ(want, got);

    want = strchr(s, '\n');
    got = ft_strchr(s, '\n');
    EXPECT_EQ(want, got);

    want = strchr(s, 'S');
    got = ft_strchr(s, 'S');
    EXPECT_EQ(want, got);
}

TEST(TestFtStrchr, FindTerminatoChar) {
    char s[] = "This is Some\ntext.\0    ";

    char *want = strchr(s,  '\0');
    char *got = ft_strchr(s, '\0');
	
    EXPECT_EQ(want, got);
}

TEST(TestFtStrchr, CharAfterTerminator) {
    char s[] = "ghreuh gkF\tEs1e24j7 k9jF?U+h+5k\0rfwfeefkkkkk";

    char *want = strchr(s, '0');
    char *got = ft_strchr(s, '0');
    EXPECT_EQ(want, got);

    want = strchr(s, 'f');
    got = ft_strchr(s, 'f');
    EXPECT_EQ(want, got);
}

TEST(TestFtStrchr, CharNotInString) {
    char s[] = "no pqrs tuv wxyz aABC DEF";

    char *want = strchr(s, ':');
    char *got = ft_strchr(s, ':');
    EXPECT_EQ(want, got);

    want = strchr(s, -49);
    got = ft_strchr(s, -49);
    EXPECT_EQ(want, got);
}

TEST(TestFtStrchr, Zero) {
    char s[] = "\0";

	char *want = strchr(s, 'a');
	char *got = ft_strchr(s, 'a');
	
	EXPECT_STREQ(want, got) << "Input: ft_strchr('\0', 'a');";
}

TEST(TestFtStrchr, Unicode) {
	char s[] = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ";

	char *want = strchr(s, L'–');
	char *got = ft_strchr(s, L'–');

	EXPECT_STREQ(want, got) << "Input: ft_strchr(\"īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ\", L'–');";
}
