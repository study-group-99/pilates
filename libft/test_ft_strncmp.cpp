#include <gtest/gtest.h>
#include <string.h>
#include <stdio.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrncmp, CompEmpty) {
    size_t  n = 0;
    char    *c1;
    char    *c2;
    int     res1;
    int     res2;
    
    res1 = strncmp(c1, c2, 0);
    res2 = ft_strncmp(c1, c2, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = strncmp(c2, c1, 0);
    res2 = ft_strncmp(c2, c1, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
}

TEST(TestFtStrncmp, CompStr) {
    size_t  n = 4;
    char    c1[8] = "Somethi";
    char    c2[8] = "Sometht";
    int     res1;
    int     res2;
    
    res1 = strncmp(c1, c2, 8);
    res2 = ft_strncmp(c1, c2, 8);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = strncmp(c2, c1, 8);
    res2 = ft_strncmp(c2, c1, 8);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = strncmp(c1, c2, 7);
    res2 = ft_strncmp(c1, c2, 7);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = strncmp(c2, c1, 7);
    res2 = ft_strncmp(c2, c1, 7);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = strncmp(c1, c2, 0);
    res2 = ft_strncmp(c1, c2, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = strncmp(c2, c1, 0);
    res2 = ft_strncmp(c2, c1, 0);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
}

TEST(TestFtStrncmp, CompLongerStr) {
    size_t  n = 4;
    char    c1[8] = "Sometht";
    char    c2[11] = "Somethting";
    char    c3[12] = "Sometht\0ing";
    int     res1;
    int     res2;
    
    res1 = strncmp(c1, c2, 10);
    res2 = ft_strncmp(c1, c2, 10);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    res1 = strncmp(c2, c1, 10);
    res2 = ft_strncmp(c2, c1, 10);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0));
    
    res1 = strncmp(c1, c3, 10);
    res2 = ft_strncmp(c1, c3, 10);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0)) << "Sometht vs Sometht\\0ing -> n = 10 -> strncmp: " << res1 << "; ft_strncmp: " << res2;
    res1 = strncmp(c3, c1, 10);
    res2 = ft_strncmp(c3, c1, 10);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0)) << "Sometht\\0ing vs Sometht -> n = 10 -> strncmp: " << res1 << "; ft_strncmp: " << res2;
}

TEST(TestFtStrncmp, CompExtra) {
    size_t  n = 4;
    char    c1[] = "Tex_klkj;%,m\tl!3,t1";
    char    c2[] = "Tex_klkj;%,m\tl!3,t1";
    char    c3[] = "";
    char    c4[] = "t";
    char    c5[] = "Sometht\0ing...";
    char    c6[] = "Sometht\0ing...";
    int     res1;
    int     res2;
    
    res1 = strncmp(c1, c2, 15);
    res2 = ft_strncmp(c1, c2, 15);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0)) << "Tex_klkj;%,m\\tl!3,t1 vs Tex_klkj;%,m\\tl!3,t1 -> n = 15 -> strncmp: " << res1 << "; ft_strncmp: " << res2;
    
    res1 = strncmp(c1, c3, 10);
    res2 = ft_strncmp(c1, c3, 10);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0)) << "Tex_klkj;%,m\\tl!3,t1 vs \"\" -> n = 10 -> strncmp: " << res1 << "; ft_strncmp: " << res2; 

    res1 = strncmp(c3, c4, 3);
    res2 = ft_strncmp(c3, c4, 3);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0)) << "\"\" vs \"\" -> n = 3 -> strncmp: " << res1 << "; ft_strncmp: " << res2;
    
    res1 = strncmp(c5, c6, 14);
    res2 = ft_strncmp(c5, c6, 14);
    EXPECT_TRUE((res1 < 0 == res2 < 0) && ((res1 == 0) == (res2 == 0)) && (res1 > 0 == res2 > 0)) << "Sometht\\0ing... vs Sometht\\0in!g.. -> n = 14 -> strncmp: " << res1 << "; ft_strncmp: " << res2;
}
