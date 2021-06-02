#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemchr, CharInArr) {
    char    s1[50] = {'0'};
    void    *p1, *p2;
    
    memcpy(s1, "This is Some\ntext.\0    ", 19);
    p1 = memchr((void *) s1, 'o', 20);
    p2 = ft_memchr((void *) s1, 'o', 20);
    EXPECT_EQ(p1, p2);
    p1 = memchr((void *) s1, 0, 20);
    p2 = ft_memchr((void *) s1, 0, 20);
    EXPECT_EQ(p1, p2);
    p1 = memchr((void *) s1, 'x', 50);
    p2 = ft_memchr((void *) s1, 'x', 50);
    EXPECT_EQ(p1, p2);
    p1 = memchr((void *) s1, '\n', 50);
    p2 = ft_memchr((void *) s1, '\n', 50);
    EXPECT_EQ(p1, p2);
    p1 = memchr((void *) s1, 'S', 50);
    p2 = ft_memchr((void *) s1, 'S', 50);
    EXPECT_EQ(p1, p2);
    p1 = memchr((void *) s1, '0', 50);
    p2 = ft_memchr((void *) s1, '0', 50);
    EXPECT_EQ(p1, p2);
}

TEST(TestFtMemchr, CharInArrLowN) {
    char    s1[50] = {'0'};
    void    *p1, *p2;
    
    memcpy(s1, "ghreuh gkF\tEs1e24j7 k9jF?U+h+5krjb u3k\0fwfeef", 40);
    p1 = memchr((void *) s1, '7', 14);
    p2 = ft_memchr((void *) s1, '7', 14);
    EXPECT_EQ(p1, p2);
    p1 = memchr((void *) s1, 'h', 0);
    p2 = ft_memchr((void *) s1, 'h', 0);
    EXPECT_EQ(p1, p2);
}

TEST(TestFtMemchr, CharNotInArr) {
    char    s1[50] = {'0'};
    void    *p1, *p2;
    
    memcpy(s1, "no pqrs tuv wxyz aABC DEF", 20);
    p1 = memchr((void *) s1, ':', 10);
    p2 = ft_memchr((void *) s1, ':', 10);
    EXPECT_EQ(p1, p2);
    p1 = memchr((void *) s1, -49, 20);
    p2 = ft_memchr((void *) s1, -49, 20);
    EXPECT_EQ(p1, p2);
}