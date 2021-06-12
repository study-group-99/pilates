#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

char f_strmapi(unsigned i, char c) { return (c + i); }

TEST(TestFtStrmapi, String) {
	char s[] = "ABCD";
	char want[] = "ACEG";

	char *got = ft_strmapi(s, f_strmapi);
	EXPECT_STREQ(want, got);
}

char f_mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

TEST(TestFtStrmapi, String2) {
	char *s = (char *)malloc(sizeof(*s) * 12);
	strcpy(s, "LoReM iPsUm");
	char *got = ft_strmapi(s, f_mapi);

	EXPECT_STREQ("lOrEm IpSuM", got);
}

TEST(TestFtStrmapi, String3) {
	char s[] = "override this !";
	char b2[0xF0];
	size_t size = strlen(s);

	for (size_t i = 0; i < size; i++)
		b2[i] = f_strmapi(i, s[i]);
	b2[size] = 0;
	char *got = ft_strmapi(s, f_strmapi);

	EXPECT_STREQ("owguvnjl(}rt\x7F-/", got);
}

TEST(TestFtStrmapi, EmptyString) {
	char *got = ft_strmapi("", f_strmapi);
	EXPECT_STREQ("", got);
}

TEST(TestFtStrmapi, MustSegfault) {
	EXPECT_EXIT((ft_strmapi(NULL, f_strmapi), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strmapi(NULL, f_strmapi);\n";
	EXPECT_EXIT((ft_strmapi("segfault", NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strmapi(\"segfault\", NULL);\n";
	EXPECT_EXIT((ft_strmapi(NULL, NULL), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_strmapi(NULL, NULL);\n";
}
