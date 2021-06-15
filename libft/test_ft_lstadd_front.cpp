#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstadd_front, Basic) {
	t_list	*got = ft_lstnew(strdup("test"));
	t_list	*want = ft_lstnew(strdup("OK"));

	ft_lstadd_front(&got, want);

    EXPECT_STREQ("test", (char *)got->next->content);
    EXPECT_STREQ("OK", (char *)got->content);
}

TEST(TestFtLstadd_front, Null) {
	t_list	*got = ft_lstnew(NULL);
	t_list	*want = ft_lstnew(strdup("OK"));

	ft_lstadd_front(&got, want);

    EXPECT_TRUE(want->content == got->content);
}

TEST(TestFtLstadd_front, Null2) {
	t_list	*got = ft_lstnew(strdup("test"));
	t_list	*want = ft_lstnew(NULL);

	ft_lstadd_front(&got, want);

    EXPECT_TRUE(want->content == got->content);
}

TEST(TestFtLstadd_front, DoubleNull) {
	t_list	*got = ft_lstnew(NULL);
	t_list	*want = ft_lstnew(NULL);

	ft_lstadd_front(&got, want);

    EXPECT_TRUE(want->content == got->content);
}
