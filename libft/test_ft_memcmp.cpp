#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemcmp, Basic) {
    char    *s1 = "Somethi";
    char    *s2 = "Sometht";

    int want = memcmp(s1, s2, 8);
    int got = ft_memcmp(s1, s2, 8);
    EXPECT_EQ(got < 0, want < 0) << "Input: ft_memcmp(\"Somethi\", \"Sometht\", 8);\n";

	s1 = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
	s2 = "\xff\0\0\xaa\0\xde\x00MBS";

	want = memcmp(s1, s2, 9);
	got = ft_memcmp(s1, s2, 9);
	EXPECT_EQ(got > 0, want > 0) << "Input: ft_memcmp(\"\\xff\\0\\0\\xaa\\0\\xde\\xffMACOSX\\xff\", \"\\xff\\0\\0\\xaa\\0\\xde\\x00MBS\", 9);\n";
}

TEST(TestFtMemcmp, IntArray) {
    int s1[] = {10, 20, 30, 40, 50};
    int s2[] = {10, 20, 30, 40, 50};
    int n = sizeof(s1)/sizeof(s1[0]);

    int want = memcmp(s2, s1, n);
    int got = ft_memcmp(s2, s1, n);
    EXPECT_EQ(got, want) << "Input: int s1[] = {10, 20, 30, 40, 50}; int s2[] = {10, 20, 30, 40, 50}; int n = sizeof(s1)/sizeof(s1[0]); ft_memcmp(s2, s1, n);\n";
    
	s1[1] = 0;
    want = memcmp(s2, s1, n);
    got = ft_memcmp(s2, s1, n);
    EXPECT_EQ(got > 0, want > 0) << "Input: int s1[] = {10, 0, 30, 40, 50}; int s2[] = {10, 20, 30, 40, 50}; int n = sizeof(s1)/sizeof(s1[0]); ft_memcmp(s2, s1, n);\n";
}

TEST(TestFtMemcmp, Int) {
    int s1 = -12345;
    int s2 = -12345;
    
    int want = memcmp(&s2, &s1, sizeof(int));
    int got = ft_memcmp(&s2, &s1, sizeof(int));
    EXPECT_EQ(got, want) << "Input: int s1 = -12345; int s2 = -12345; ft_memcmp(&s2, &s1, sizeof(int));\n";

    s1 = 155;
    s2 = -35;
    want = memcmp(&s2, &s1, sizeof(int));
    got = ft_memcmp(&s2, &s1, sizeof(int));
    EXPECT_EQ(got > 0, want > 0) << "Input: s1 = 155;  s2 = -35; ft_memcmp(&s2, &s1, sizeof(int);\n";
}

TEST(TestFtMemcmp, CharInt) {
    int s1[] = {104, 101, 108, 108, 111};
    char s2[6] = "hello";
    
    int want = memcmp(s1, s2, 6);
    int got = ft_memcmp(s1, s2, 6);
    EXPECT_EQ(got < 0, want < 0) << "Input: int s1[] = {104, 101, 108, 108, 111}; char s2[6] = \"hello\"; ft_memcmp(s1, s2, 6);\n";
}

TEST(TestFtMemcmp, Zero) {
    char *s1 = "atoms\0\0\0\0";
	char *s2 = "atoms\0abc";

	int want = memcmp(s1, s2, 8);
	int	got = ft_memcmp(s1, s2, 8);

    EXPECT_EQ(got < 0, want < 0) << "Input: char *s1 = \"atoms\\0\\0\\0\\0\"; char *s2 = \"atoms\\0abc\"; ft_memcmp(s1, s2, 8);\n";
}

TEST(TestFtMemcmp, Unsigned) {
    char *s1 = "\xff\xaa\xde\200";
	char *s2 = "\xff\xaa\xde\0";

	int want = memcmp(s1, s2, 8);
	int	got = ft_memcmp(s1, s2, 8);

    EXPECT_EQ(got, want) << "Input: char *s1 = \"\\xff\\xaa\\xde\\200\"; char *s2 = \"\\xff\\xaa\\xde\\0\"; ft_memcmp(s1, s2, 8);\n";
}

TEST(TestFtMemcmp, Empty) {
    char *s1, *s2;

    int want = memcmp(s1, s2, 0);
    int got = ft_memcmp(s1, s2, 0);
    EXPECT_EQ(got, want) << "Input: char    *s1, *s2; ft_memcmp(s1, s2, 0);";
}

TEST(TestFtMemcmp, MustSegfault) {
	EXPECT_EXIT((ft_memcmp("test", NULL, 4), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memcmp(\"test\", NULL, 4);\n";
	EXPECT_EXIT((ft_memcmp(NULL, "test", 4), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memcmp(NULL, s, 4);\n";
}
