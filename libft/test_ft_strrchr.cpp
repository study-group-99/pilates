#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrrchr, CharInStr) {
    char    s[50] = {'0'};
    memcpy(s, "This is Some\ntext.\0    ", 19);

    EXPECT_EQ(strrchr(s, 'o'), ft_strrchr(s, 'o')) << "Input: char s[50] = {'0'}; memcpy(s, \"This is Some\\ntext.\\0    \", 19); ft_strrchr(s, 'o')";
    EXPECT_EQ(strrchr(s, 'x'), ft_strrchr(s, 'x')) << "Input: char s[50] = {'0'}; memcpy(s, \"This is Some\\ntext.\\0    \", 19); ft_strrchr(s, 'x')";
    EXPECT_EQ(strrchr(s, '\n'), ft_strrchr(s, '\n')) << "Input: char s[50] = {'0'}; memcpy(s, \"This is Some\\ntext.\\0    \", 19); ft_strrchr(s, '\n')";
    EXPECT_EQ(strrchr(s, 'S'), ft_strrchr(s, 'S')) << "Input: char s[50] = {'0'}; memcpy(s, \"This is Some\\ntext.\\0    \", 19); ft_strrchr(s, 'S')";
}

TEST(TestFtStrrchr, FindTerminatoChar) {
    char s[50] = {'0'};
    memcpy(s, "This is Some\ntext.\0    ", 19);

    EXPECT_EQ(strrchr(s,  0), ft_strrchr(s,  0)) << "Input: char s[50] = {'0'}; memcpy(s, \"This is Some\\ntext.\\0    \", 19); ft_strrchr(s,  0)";
}

TEST(TestFtStrrchr, CharAfterTerminator) {
    char s[50] = {'0'};
    memcpy(s, "ghreuh gkF\tEs1e24j7 k9jF?U+h+5k\0rfwfeefkkkkk", 40);

    EXPECT_EQ(strrchr(s, '0'), ft_strrchr(s, '0')) << "Input: char s[50] = {'0'}; memcpy(s, \"ghreuh gkF\\tEs1e24j7 k9jF?U+h+5k\\0rfwfeefkkkkk\", 40); ft_strrchr(s, '0')";
    EXPECT_EQ(strrchr(s, 'f'), ft_strrchr(s, 'f')) << "Input: char s[50] = {'0'}; memcpy(s, \"ghreuh gkF\\tEs1e24j7 k9jF?U+h+5k\\0rfwfeefkkkkk\", 40); ft_strrchr(s, 'f')";
}

TEST(TestFtStrrchr, CharNotInStr) {
    char s[50] = {'0'};
    s[50] = 0;
    memcpy(s, "no pqrs tuv wxyz aABC DEF", 20);

    EXPECT_EQ(strrchr(s, ':'), ft_strrchr(s, ':')) << "Input: s[50] = 0; memcpy(s, \"no pqrs tuv wxyz aABC DEF\", 20); ft_strrchr(s, ':')";
    EXPECT_EQ(strrchr(s, -49), ft_strrchr(s, -49)) << "Input: s[50] = 0; memcpy(s, \"no pqrs tuv wxyz aABC DEF\", 20); ft_strrchr(s, -49)";
}

TEST(TestFtStrrchr, Unicode) {
	char *got = ft_strrchr("īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ", L'–');
	EXPECT_STREQ(NULL, got) << "Input: char *got = ft_strrchr(\"īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ\", L'–');";
}

TEST(TestFtStrrchr, Empty) {
	char *got = ft_strrchr("\0", 'a');
	EXPECT_STREQ(NULL, got) << "Input: char *got = ft_strrchr(\"\\0\", 'a');";
}

TEST(TestFtStrrchr, MustSegfault) {
	EXPECT_EXIT((ft_strrchr(NULL, '\0'), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strrchr(NULL, '\0');\n";
}
