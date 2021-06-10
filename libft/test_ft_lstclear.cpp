#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

void lstclear_f(void *elem) {
	*(int *)elem *= 10;
}

TEST(TestFtLstclear, Basic) {
	t_list *s1 = (t_list *)malloc(sizeof(t_list));
	t_list *s2 = (t_list *)malloc(sizeof(t_list));
	t_list *s3 = (t_list *)malloc(sizeof(t_list));
	int got1 = 1;
	int got2 = 2;
	int got3 = 3;
	s1->next = s2;
	s1->content = &got1;
	s2->next = s3;
	s2->content = &got2;
	s3->next = NULL;
	s3->content = &got3;
	t_list	*got = s1;

	ft_lstclear(&got, lstclear_f);

	EXPECT_TRUE(got1 == 10);
	EXPECT_TRUE(got2 == 20);
	EXPECT_TRUE(got3 == 30);
	EXPECT_TRUE(got == NULL);
}

TEST(TestFtLstclear, Null) {
	t_list	*got = NULL;
	ft_lstclear(&got, lstclear_f);
	EXPECT_TRUE(got == NULL);
}
