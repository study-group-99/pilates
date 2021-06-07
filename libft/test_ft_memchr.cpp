#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemchr, Basic) {
    char 	*s = "    /|\x12\xff\x09\x42\042\42|\\This is Some\ntext.\0    ";
	void   	*got, *want;

    got = ft_memchr((void *) s, 'o', 38);
    want = memchr((void *) s, 'o', 38);
    EXPECT_EQ(got, want) << "Input: ft_memchr((void *)\"    /|\\x12\\xff\\x09\\x42\\042\\42|\\This is Some\ntext.\0    \", 'o', 38);\n";

    got = ft_memchr((void *) s, 0, 38);
	want = memchr((void *) s, 0, 38);
	EXPECT_EQ(got, want) << "Input: ft_memchr((void *)\"    /|\\x12\\xff\\x09\\x42\\042\\42|\\This is Some\ntext.\0    \", 0, 38);\n";
}

TEST(TestFtMemchr, Basic2) {
	char	*s = "  /|\x12\xff\x09\x42\042\200\42|\\This is Some\ntext3.\0    ";
	void   	*got, *want;

    got = ft_memchr((void *) s, '\x42', 3);
    want = memchr((void *) s, '\x42', 3);
    EXPECT_EQ(got, want) << "Input: ft_memchr((void *)\"  /|\\x12\\xff\\x09\\x42\\042\\42|\\This is Some\ntext3.\0    \", 'o', 3);\n";
    
	got = ft_memchr((void *) s, '\xde', 38);
    want = memchr((void *) s, '\xde', 38);
    EXPECT_EQ(got, want) << "Input: ft_memchr((void *)\"  /|\\x12\\xff\\x09\\x42\\042\\42|\\This is Some\ntext3.\0    \", 'o', 38);\n";
}

TEST(TestFtMemchr, Unsigned) {
	char	*s = "  /|\x12\xff\x09\x42\042\200\42|\\This is Some\ntext3.\0    ";
    void	*got = ft_memchr((void *) s, '\200', 38);
    void	*want = memchr((void *) s, '\200', 38);

    EXPECT_EQ(got, want) << "Input: ft_memchr((void *)\"  /|\\x12\\xff\\x09\\x42\\042\\42|\\This is Some\ntext3.\0    \", 'o', 38);\n";
}

TEST(TestFtMemchr, ZeroByte) {
	char	*s = "  /|\x12\xff\x09\x42\042\200\42|\\This is Some\ntext3.\0    ";
    void	*got = ft_memchr((void *) s, '\0', 30);
    void	*want = memchr((void *) s, '\0', 30);

    EXPECT_EQ(got, want) << "Input: ft_memchr((void *)\"  /|\\x12\\xff\\x09\\x42\\042\\42|\\This is Some\ntext3.\0    \", 'o', 30);\n";
}

TEST(TestFtMemchr, MustSegfault) {
	EXPECT_EXIT((ft_memchr(NULL, '\0', 0x20), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memchr(NULL, '\0', 0x20);\n";
}
