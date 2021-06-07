#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemmove, Basic) {
	char *s = "This is some text.";
    char want[50] = {'0'};
    char got[50] = {'0'};
    
    memmove((void *)want, s, 19); ft_memmove((void *)got, s, 19);

    EXPECT_STREQ(want, got) << "Input: char got[50] = {'0'}; ft_memmove((void *)got, \"This is some text.\", 19)";
}

TEST(TestFtMemmove, Return) {
	char *s = "This is some text.";
    char s1[50] = {'0'};
    char s2[50] = {'0'};
    
    void *want = memmove((void *)s1, s, 19); 
	void *got = ft_memmove((void *)s2, s, 19);
	
    EXPECT_STREQ((char *)want, (char *)got) << "Input: char s2[50] = {'0'}; void *got = ft_memmove((void *)s2, \"This is some text.\", 19)";
}

TEST(TestFtMemmove, ZeroCheck) {
	char *s = "This is some text.";
    char want[50] = {'0'};
    char got[50] = {'0'};

    memmove((void *)want, s, 0); ft_memmove((void *)got, s, 0);

    EXPECT_STREQ(want, got) << "Input: char got[50] = {'0'}; ft_memmove((void *)got, \"This is some text.\", 0);";
}

TEST(TestFtMemmove, ZeroCheckReturn) {
	char *s = "This is some text.";
	char s1[50] = {'0'};
    char s2[50] = {'0'};

    void *want = memmove((void *) s1, s, 0);
    void *got = ft_memmove((void *) s2, s, 0);

    EXPECT_STREQ((char *)want, (char *)got);
}

TEST(TestFtMemmove, Unsigned) {
	char *s = "thi\xffs i\xfas \0a g\xde\xadood \0nonono\0dog\0 !\r\n";
	char want[0xF0], got[0xF0];

	memmove(want, s, 33); ft_memmove(got, s, 33);

	EXPECT_STREQ(want, got) << "Input: char got[0xF0]; ft_memmove(got, \"thi\\xffs i\\xfas \\0a g\\xde\\xadood \\0nonono\\0dog\\0 !\\r\\n\", 33);";
}

TEST(TestFtMemmove, IntegerCopy) {
	unsigned long s = 0xdeadbeef;
	int	size = sizeof(s);
	unsigned long want;
	unsigned long got;

	memmove(&want, &s, size); ft_memmove(&got, &s, size);

	EXPECT_TRUE(want == got) << "Input: unsigned long s = 0xdeadbeef; int size = sizeof(s);	unsigned long got; ft_memmove(&got, &s, size);";
}

TEST(TestFtMemmove, Overlap1) {
	char *s = "++++++++++";
	char want[240], got[240];
	int	size = 240 - 15;

	memset(want, 'A', sizeof(want)-1);
	memcpy(want, s, strlen(s));
	
	memset(got, 'A', sizeof(got)-1); 
	memcpy(got, s, strlen(s));
	
	memmove(want + 3, want, size); ft_memmove(got + 3, got, size);
	
	EXPECT_STREQ(want, got) << "Input: overlap";
}

TEST(TestFtMemmove, Overlap2) {
	char *s = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
	char got[0xF0], want[0xF0];
	int	size = 0xF0 - 0xF;

	memset(want, 'A', sizeof(want)-1);
	memcpy(want, s, strlen(s));

	memset(got, 'A', sizeof(got)-1); 
	memcpy(got, s, strlen(s)); 

	memmove(got, got + 3, size); ft_memmove(want, want + 3, size);

	EXPECT_STREQ(want, got) << "Input: overlap";
}

TEST(TestFtMemmove, BigSize) {
	int	size = 128 * 1024 * 1024;
	char *got = (char *)malloc(sizeof(char) * size);
	char *want = (char *)malloc(sizeof(char) * size);
	memset(want, 'A', size); 
	
	ft_memmove(got, want, size);

	EXPECT_STREQ(want, got) << "Input: int size = 128 * 1024 * 1024; char *got = (char *)malloc(sizeof(char) * size); char *want = (char *)malloc(sizeof(char) * size); ft_memmove(got, want, size);";
}

TEST(TestFtMemmove, MustSegfault) {
	char b[0xF0];
	EXPECT_EXIT((ft_memmove(NULL, b, 5), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memccpy((void *)\"\", \"it should segfault\", '\0', 17);\n";
	EXPECT_EXIT((ft_memmove(b, NULL, 5), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_memccpy((void *)\"\", \"it should segfault\", '\0', 17);\n";
}

TEST(TestFtMemmove, DoubleNull) {
	void *got = ft_memmove(NULL, NULL, 0);
	EXPECT_EQ(NULL, got) << "Input: void *got = ft_memmove(NULL, NULL, 0);";

	got = ft_memmove(NULL, NULL, 5);
	EXPECT_EQ(NULL, got) << "Input: void *got = ft_memmove(NULL, NULL, 5);";
}
