#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrlen, SimpleText) {
    char s[] = "Test123";
    int want = strlen(s);
	int got = ft_strlen(s);

    EXPECT_EQ(want, got);
}

TEST(TestFtStrlen, ZeroText) {
    char s[] = "";
    int want = strlen(s);
	int got = ft_strlen(s);

    EXPECT_EQ(want, got);
}

TEST(TestFtStrlen, WithSpecChar) {
    char s1[] = "Té:_÷×ßŁst\0T";
	int want = strlen(s1);
	int got = ft_strlen(s1);

    EXPECT_EQ(want, got);

    char s2[] = "T\tT";
    want = strlen(s2);
	got = ft_strlen(s2);

    EXPECT_EQ(want, got);
}

TEST(TestFtStrlen, SimpleText2) {
	const char *s = "01234567, AAAAAA, abc\xba e, ......, end of string !";
	int want = strlen(s);
	int got = ft_strlen(s);

    EXPECT_EQ(want, got);
}

TEST(TestFtStrlen, Unicode) {
	char s[] = "♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪";
	int want = strlen(s);
	int got = ft_strlen(s);

    EXPECT_EQ(want, got);
}

TEST(TestFtStrlen, NonAligned) {
	const char	*s = "YOLO";

	if ((unsigned long)s & 0b111)
		s++;

	int want = strlen(s);
	int got = ft_strlen(s);
	
    EXPECT_EQ(want, got);
}
