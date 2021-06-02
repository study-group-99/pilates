#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtMemcpy, CpyCharArr) {
    char    s3[19] = "0";
    char    s4[19] = "0";
    void    *s5;
    int     out = 0;

    memcpy(s3, "This is some text.", 19);
    s5 = ft_memcpy(s4, "This is some text.", 19);
    ASSERT_TRUE(s4 != 0);
    ASSERT_TRUE(s5 != 0);
    EXPECT_EQ(s5,s4);
    EXPECT_EQ(0, memcmp(s3, s4, 19));
    
    s5 = ft_memcpy(s3, "Some other random text for s3", 30);
    ASSERT_TRUE(s3 != 0);
    s5 = ft_memcpy(s4, s3, 19);
    ASSERT_TRUE(s4 != 0);
    s5 = ft_memcpy(s3, "", 0);
    ASSERT_TRUE(s3 != 0);
    EXPECT_EQ(0, memcmp(s3, s4, 19));
}

TEST(TestFtMemcpy, CpyIntArr) {
    int isrc[] = {10, 20, 30, 40, 50};
    int isrc2[] = {10, 20, 30, 40, 50};
    int n = sizeof(isrc)/sizeof(isrc[0]);
    int idest[n], idest2[n];
    memcpy(idest, isrc,  sizeof(isrc));
    ft_memcpy(idest2, isrc2,  sizeof(isrc2));
    EXPECT_EQ(0, memcmp(idest, idest2, n));
}

TEST(TestFtMemcpy, Extra) {
	const char src[] = "th%^ is the source";
	char dst[] = "destination";
	ft_memcpy(dst, src, 10);
	EXPECT_EQ(*dst, *src);

	ASSERT_TRUE(ft_memcpy(NULL, NULL, 0) == NULL);
	ASSERT_TRUE(ft_memcpy(NULL, NULL, 3) == NULL);
}
