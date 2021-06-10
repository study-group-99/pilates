#include <gtest/gtest.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtAtoi, ReadSimpleText) {
    char s1[] = "101";
    char s2[] = "-102";

	int	want = atoi(s1);
	int got = ft_atoi(s1);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"101\");\n";

	want = atoi(s2);
	got = ft_atoi(s2);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"-102\");\n";
}

TEST(TestFtAtoi, ReadWrongTextAsZero) {
    char s1[] = "^%,.103";
    char s2[] = "+-+-104";
    
	int	want = atoi(s1);
	int got = ft_atoi(s1);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"^%,.103\");\n";

	want = atoi(s2);
	got = ft_atoi(s2);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"+-+-104\");\n";
}

TEST(TestFtAtoi, ReadTextFollowedByChars) {
    char s1[] = "+\tddgg+\v\f\r\n \f1234107!.dr";
    char s2[] = "\t\v\f\r\n \f+-108fef1100";

	int	want = atoi(s1);
	int got = ft_atoi(s1);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"107!.dr\");\n";

	want = atoi(s2);
	got = ft_atoi(s2);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"-108fef1100\");\n";
}

TEST(TestFtAtoi, HandleCombinations) {
    char s1[] = "\t\v\f\r\n \f+\t\v\f\r\n \f1234123ff\t\v\f\r\n \f+\t\v\f";
    char s2[] = "\t\v\f\r\n \f- \f\t\n\r    98764";

	int	want = atoi(s1);
	int got = ft_atoi(s1);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"\\t\\v\\f\\r\\n \\f+\\t\\v\\f\\r\\n \\f1234123ff\\t\\v\\f\\r\\n \\f+\\t\\v\\f\");";

	want = atoi(s2);
	got = ft_atoi(s2);
    EXPECT_EQ(got , want) << "Input: ft_atoi(\"\\t\\v\\f\\r\\n \\f- \\f\\t\\n\\r    98764\");\n";
}

TEST(TestFtAtoi, ReadMaxAndMinInt) {
    char *s1 = "-2147483648";
    char *s2 = "2147483647";
    
	int	want = atoi(s1);
	int	got = ft_atoi(s1);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"-2147483648\")\n";
	
	want = atoi(s2);
	got = ft_atoi(s2);
    EXPECT_EQ(got, want) << "Input: ft_atoi(\"-2147483648\")\n";
}

TEST(TestFtAtoi, MustSegfault) {
	EXPECT_EXIT((ft_atoi(NULL),exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_atoi(NULL);\n";
}
