#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstnew, CheckOfSizeT) {
	size_t	n = 4;
	t_list	*testObj;
	size_t	*out;
	
	testObj = ft_lstnew(&n);
	out = (size_t*)testObj->content;
	EXPECT_EQ(*out, n);
	ASSERT_TRUE(testObj->next == NULL);
	ASSERT_TRUE(testObj->content == &n);

	free(testObj);
}

TEST(TestFtLstnew, CheckOfChar) {
	char	c[] = "lkjlk";
	t_list	*testObj;
	
	testObj = ft_lstnew(c);
	EXPECT_EQ(0, strcmp((const char*)(testObj->content), c));
	ASSERT_TRUE(testObj->next == NULL);
	ASSERT_TRUE(testObj->content == c);

	free(testObj);
}

TEST(TestFtLstnew, CheckOfInt) {
	int		c = 1585;
	t_list	*testObj;
	
	testObj = ft_lstnew(&c);
	EXPECT_EQ(*(int*)(testObj->content), c);
	ASSERT_TRUE(testObj->next == NULL);
	ASSERT_TRUE(testObj->content == &c);

	free(testObj);
}

TEST(TestFtLstnew, CheckOfLong) {
	long long int	c = 42147483647;
	t_list	*testObj;
	
	testObj = ft_lstnew(&c);
	EXPECT_EQ(*(long long int*)(testObj->content), c);
	ASSERT_TRUE(testObj->next == NULL);
	ASSERT_TRUE(testObj->content == &c);

	free(testObj);
}
