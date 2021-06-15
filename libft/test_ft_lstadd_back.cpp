#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstadd_back, Basic) {
	t_list	*got = ft_lstnew(strdup("test"));
	t_list	*want = ft_lstnew(strdup("OK"));

	ft_lstadd_back(&got, want);

    EXPECT_TRUE(want == got->next);
    EXPECT_STREQ("OK", (char *)got->next->content);
}

TEST(TestFtLstadd_back, Null) {
	t_list	*got = ft_lstnew(NULL);
	t_list	*want = ft_lstnew(strdup("OK"));

	ft_lstadd_back(&got, want);

    EXPECT_TRUE(want->content == got->next->content);
}

TEST(TestFtLstadd_back, Null2) {
	t_list	*got = ft_lstnew(strdup("test"));
	t_list	*want = ft_lstnew(NULL);

	ft_lstadd_back(&got, want);

    EXPECT_TRUE(want->content == got->next->content);
}

TEST(TestFtLstadd_back, DoubleNull) {
	t_list	*got = ft_lstnew(NULL);
	t_list	*want = ft_lstnew(NULL);

	ft_lstadd_back(&got, want);

	EXPECT_TRUE(NULL == got->content);
	EXPECT_TRUE(want == got->next);
}
