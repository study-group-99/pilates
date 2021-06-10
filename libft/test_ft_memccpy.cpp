#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemccpy, BasicEmptyBuffer) {
	char s[] = "this is some text .";
    char got[20] = "";
    char want[20] = "";
    
    ft_memccpy(got, s, 'i', 5); memccpy(want, s, 'i', 5);

    EXPECT_STREQ(want, got) << "Input: ft_memccpy(\"\", \"this is some text .\", 'i', 5);\n";
}

TEST(TestFtMemccpy, BasicFilledBuffer) {
	char s[] = "this is some other text, slightly different !";
	char got[] = "test me";
	char want[] = "test me";

	ft_memccpy(got, s, ' ', strlen(s)); memccpy(want, s, ' ', strlen(s));
	
	EXPECT_STREQ(want, got) << "Input: ft_memccpy(\"test me\", \"this is some other text, slightly different !\", ' ', strlen(s));\n";
}

TEST(TestFtMemccpy, unsignedChar) {
	char s[] = "string with\200inside !";
	char got[] = "abcdefghijklmnopqrstuvwxyz";
	char want[] = "abcdefghijklmnopqrstuvwxyz";

	ft_memccpy(got, s, '\200', 30); memccpy(want, s, '\200', 30);

	EXPECT_STREQ(want, got) << "Input: char s[] = \"string with\\200inside !\"; ft_memccpy(\"abcdefghijklmnopqrstuvwxyz\", s, '\\200', 21);\n";
}

TEST(TestFtMemccpy, StopUnsignedChar) {
	char s[] = "string with\200inside !";
	char got[] = "abcdefghijklmnopqrstuvwxyz";
	char want[] = "abcdefghijklmnopqrstuvwxyz";

	ft_memccpy(got, s, 0600, 30); memccpy(want, s, 0600, 30);

	EXPECT_STREQ(want, got) << "Input: char s[] = \"string with\\200inside !\"; ft_memccpy(\"abcdefghijklmnopqrstuvwxyz\", s, '\\200', 21);\n";
}

TEST(TestFtMemccpy, BasicReturn) {
	char s[] = "this is some text ."; 
	char b[11];   

    char *got = (char *)ft_memccpy(b, s, 'o', 11); 
	char *want = (char *)memccpy(b, s, 'o', 11);

    EXPECT_STREQ(want, got) << "Input: char b[11]; char *got = (char *)ft_memccpy(b, \"this is some text .\", 'o', 11);\n";
}

TEST(TestFtMemccpy, NotFoundChar) {
	char s[] = "this is some text ."; 
	char b1[11];
	char b2[11];

	char *got = (char *)ft_memccpy(b1, s, 'a', 11);
	char *want = (char *)memccpy(b2, s, 'a', 11);

	EXPECT_STREQ(want, got) << "Input: char	b1[11]; char *got = (char *)ft_memccpy(b1, s, 'a', 11);\n";
}

TEST(TestFtMemccpy, Zero) {
	const char *s = "test 0 \0the\0 memccpy !";
	char want[] = "phrase different then the test";
	char got[] = "phrase different then the test";

	ft_memccpy(got, s, '\0', 0);
	EXPECT_STREQ(want, got) << "Input: char	s[] = \"test 0 \0the\0 memccpy !\"; ft_memccpy(\"phrase different then the test\", s, '\0', 0);\n";
}

typedef struct	s_tests {
	char c[128];
	void *v;
	unsigned long long int ui;
	int	i;
}				t_test;

TEST(TestFtMemccpy, Struct) {
	t_test	s[] = {"thanks to alelievr for these test cases", (void*)0xdeadbeef, 0x42424242424242L, 0b1010100010};
	char got[0xF00];
	char want[0xF00];

	ft_memccpy(got, s, '\x42', sizeof(s)); memccpy(want, s, '\x42', sizeof(s));
	EXPECT_STREQ(want, got) << "Input: too complex to return, check the source\n";
}

TEST(TestFtMemccpy, MustSegfault) {
	EXPECT_EXIT((ft_memccpy((void *)"", "segfault", '\0', 17), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memccpy((void *)\"\", \"it should segfault\", '\0', 17);\n";
	EXPECT_EXIT((ft_memccpy(NULL, "segfault", 'e', 17), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memccpy(NULL, \"segfault\", 'e', 17);\n";
	EXPECT_EXIT((ft_memccpy((void *)"            ", NULL, ' ', 17), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memccpy((void *)\"            \", NULL, ' ', 17);\n";
}
