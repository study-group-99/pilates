#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemccpy, CharInArr) {
    char    s1[50] = {'0'};
    char    s2[50] = {'0'};
    void    *p1, *p2;
    
    p1 = memccpy((void *) s1, "This is some text.", 'o', 19);
    p2 = ft_memccpy((void *)s2, "This is some text.", 'o', 19);
    ASSERT_TRUE(p2 != 0);
    EXPECT_EQ(s1 - ((char *)p1), s2 - ((char *)p2));
    EXPECT_EQ(0, memcmp(s1, s2, 50));    
}

TEST(TestFtMemccpy, CharNotInArr) {
    char    s1[50] = {'0'};
    char    s2[50] = {'0'};
    void    *p1, *p2;

    p1 = memccpy((void *) s1, "This is some text.", 'z', 19);
    p2 = ft_memccpy((void *) s2, "This is some text.", 'z', 19);
    EXPECT_EQ(p1, p2);
    EXPECT_EQ(0, memcmp(s1, s2, 50));
}

TEST(TestFtMemccpy, ZeroCheck) {
    char    s1[50] = {'0'};
    char    s2[50] = {'0'};
    void    *p1, *p2;

    p1 = memccpy((void *) s1, "This is some text.", 'z', 0);
    p2 = ft_memccpy((void *) s2, "This is some text.", 'z', 0);
    EXPECT_EQ(p1, p2);
}
