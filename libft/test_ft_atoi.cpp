#include <gtest/gtest.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtAtoi, ReadSimpleText) {
    char s1[] = "+100";
    char s2[] = "-101";
    char s3[] = "102";
    
    EXPECT_EQ(atoi(s1), ft_atoi(s1));
    EXPECT_EQ(atoi(s2), ft_atoi(s2));
    EXPECT_EQ(atoi(s3), ft_atoi(s3));
}

TEST(TestFtAtoi, ReadWrongTextAsZero) {
    char s1[] = ",-103";
    char s2[] = "+-+-104";
    char s3[] = ".105";
    char s4[] = "--106";
    
    EXPECT_EQ(atoi(s1), ft_atoi(s1));
    EXPECT_EQ(atoi(s2), ft_atoi(s2));
    EXPECT_EQ(atoi(s3), ft_atoi(s3));
    EXPECT_EQ(atoi(s4), ft_atoi(s4));
}

TEST(TestFtAtoi, ReadTextFollowedByChars) {
    char s1[] = "107!.";
    char s2[] = "-108fef1100";
    char s3[] = "-109dwd";

    EXPECT_EQ(atoi(s1), ft_atoi(s1));
    EXPECT_EQ(atoi(s2), ft_atoi(s2));
    EXPECT_EQ(atoi(s3), ft_atoi(s3));
}

TEST(TestFtAtoi, HandleWhiteSpacesSeparately) {
    char s1[] = " 110";
    char s2[] = "\n111";
    char s3[] = "\t112";
    char s4[] = "\r113";
    char s5[] = "\f114";
    char s6[] = "\v115";
    char s7[] = "\b116";

    EXPECT_EQ(atoi(s1), ft_atoi(s1));
    EXPECT_EQ(atoi(s2), ft_atoi(s2));
    EXPECT_EQ(atoi(s3), ft_atoi(s3));
    EXPECT_EQ(atoi(s4), ft_atoi(s4));
    EXPECT_EQ(atoi(s5), ft_atoi(s5));
    EXPECT_EQ(atoi(s6), ft_atoi(s6));
    EXPECT_EQ(atoi(s7), ft_atoi(s7));
}

TEST(TestFtAtoi, HandleCombinations) {
    char s1[] = "    117fefv";
    char s2[] = "\n \n 118";
    char s3[] = " \t \r \f 119";
    char s4[] = "\r \v 120flkk1111";
    char s5[] = " \f \b 121";
    char s6[] = "\v - 122";
    char s7[] = " \n + 123ff";

    EXPECT_EQ(atoi(s1), ft_atoi(s1));
    EXPECT_EQ(atoi(s2), ft_atoi(s2));
    EXPECT_EQ(atoi(s3), ft_atoi(s3));
    EXPECT_EQ(atoi(s4), ft_atoi(s4));
    EXPECT_EQ(atoi(s5), ft_atoi(s5));
    EXPECT_EQ(atoi(s6), ft_atoi(s6));
    EXPECT_EQ(atoi(s7), ft_atoi(s7));
}

TEST(TestFtAtoi, ReadMaxAndMinInt) {
    char s1[] = "-2147483648";
    char s2[] = "2147483647";
    
    EXPECT_EQ(atoi(s1), ft_atoi(s1));
    EXPECT_EQ(atoi(s2), ft_atoi(s2));
}
