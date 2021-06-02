#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemmove, CharInArr) {
    char    s1[50] = {'0'};
    char    s2[50] = {'0'};
    void    *p1, *p2;
    
    p1 = memmove((void *) s1, "This is some text.", 19);
    p2 = ft_memmove((void *)s2, "This is some text.", 19);
    ASSERT_TRUE(p2 != 0);
    EXPECT_EQ(s1 - ((char *)p1), s2 - ((char *)p2));
    EXPECT_EQ(0, memcmp(s1, s2, 50));    
}

TEST(TestFtMemmove, CharNotInArr) {
    char    s1[50] = {'0'};
    char    s2[50] = {'0'};
    void    *p1, *p2;

    p1 = memmove((void *) s1, "This is some text.", 19);
    p2 = ft_memmove((void *) s2, "This is some text.", 19);
    // EXPECT_EQ(p1, p2);
    EXPECT_EQ(0, memcmp(s1, s2, 50));
}

TEST(TestFtMemmove, ZeroCheck) {
    char    s1[50] = {'0'};
    char    s2[50] = {'0'};
    void    *p1, *p2;

    p1 = memmove((void *) s1, "This is some text.", 0);
    p2 = ft_memmove((void *) s2, "This is some text.", 0);
    ASSERT_STREQ((char *) p1, (char *) p2);

	ASSERT_TRUE(ft_memmove(NULL, NULL, 5) == NULL);
}
