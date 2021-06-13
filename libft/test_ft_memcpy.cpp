#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemcpy, Basic) {
	char s[] =  "This is some text.";
    char got[19] = "0";
    char want[19] = "0";

    memcpy(want, s, 19); ft_memcpy(got, s, 19);

    EXPECT_STREQ(want, got) << "Input: char *s =  \"This is some text.\"; char got[19] = \"0\"; ft_memcpy(got, s, 19)";
}

TEST(TestFtMemcpy, Basic2) {
	char s[] =  "other random text!";
    char got[19] = "0";
    char want[19] = "0";

    memcpy(want, s, 19); ft_memcpy(got, s, 19);

    EXPECT_STREQ(want, got) << "Input: char *s =  \"other random text!\"; char got[19] = \"0\"; ft_memcpy(got, s, 19)";
}

TEST(TestFtMemcpy, BasicInt) {
    int s[] = {10, 20, 30, 40, 50};
    int want[5], got[5];

    memcpy(want, s,  sizeof(s)); ft_memcpy(got, s,  sizeof(s));
    
	EXPECT_EQ(got[4], want[4]) << "Input: int s[] = {10, 20, 30, 40, 50}; int got[5]; ft_memcpy(got, s,  sizeof(s));";
}

TEST(TestFtMemcpy, BasicReturn) {
    char s1[49] = "0";
    char s2[49] = "0";
	char s[] = "This is some text.";

    void *want = memcpy(s1, s, 19);
    void *got = ft_memcpy(s2, s, 19);
    EXPECT_STREQ((char *)got, (char *)want) << "Input: char s2[49] = \"0\"; char *s = \"This is some text.\"; ft_memcpy(s2, s, 19);";
}

TEST(TestFtMemcpy, ZeroLength) {
	const char *s = "th%^ is the source";
	char want[] = "destination";
	char got[] = "destination";

	ft_memcpy(got, s, 0);
	EXPECT_STREQ(want, got) << "Input: ft_memcpy(\"destination\", \"th%^ is the source\", 0);";
}

typedef struct	s_tests {
	char					c[128];
	void					*v;
	unsigned long long int	ui;
	int						i;
}				t_test;

TEST(TestFtMemcpy, Struct) {
	t_test	s[] = {"thanks to alelievr for these test cases", (void*)0xdeadbeef, 0x42424242424242L, 0b1010100010};
	char	got[0xF00];
	char	want[0xF00];

	memcpy(want, s, sizeof(s)); ft_memcpy(got, s, sizeof(s)); 
	
	EXPECT_STREQ(want, got);
}

TEST(TestFtMemcpy, ZeroDestination) {
	EXPECT_EXIT((ft_memcpy((void *)"", "segfault", 20),exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memcpy(\"\", \"segfault\", 20;\n";
}
