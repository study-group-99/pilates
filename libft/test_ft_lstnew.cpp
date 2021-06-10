#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstnew, Size) {
	size_t n = 4;
	t_list *got = ft_lstnew(&n);

	EXPECT_TRUE(got->next == NULL);
	EXPECT_TRUE(got->content == &n);
}

TEST(TestFtLstnew, Char) {
	char want[] = "this is a test";
	t_list *got = ft_lstnew(want);

	EXPECT_TRUE(NULL == got->next);
	EXPECT_TRUE(&want == got->content);
}

TEST(TestFtLstnew, Integer) {
	int	want = 1585;
	t_list *got = ft_lstnew(&want);

	EXPECT_TRUE(NULL == got->next);
	EXPECT_TRUE(&want == got->content);
}

TEST(TestFtLstnew, Long) {
	long long int want = 42147483647;
	t_list *got = ft_lstnew(&want);

	EXPECT_TRUE(NULL == got->next);
	EXPECT_TRUE(&want == got->content);
}

TEST(TestFtLstnew, Null) {
	t_list *got = ft_lstnew(NULL);
	
	EXPECT_TRUE(NULL == got->next);
	EXPECT_TRUE(NULL == got->content);
}
