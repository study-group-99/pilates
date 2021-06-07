#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

void	DelProto(void *elem)
{
	*(int *)elem *= 10;
}

TEST(TestFtLstclear, ThreeElemLst) {
	t_list *e1 = (t_list *)malloc(sizeof(t_list));
	t_list *e2 = (t_list *)malloc(sizeof(t_list));
	t_list *e3 = (t_list *)malloc(sizeof(t_list));
	int cont1 = 1;
	int cont2 = 2;
	int cont3 = 3;
	e1->next = e2;
	e1->content = &cont1;
	e2->next = e3;
	e2->content = &cont2;
	e3->next = NULL;
	e3->content = &cont3;
	t_list	*head;

	head = e1;
	ft_lstclear(&head, &DelProto);
	EXPECT_TRUE(cont1 == 10);
	EXPECT_TRUE(cont2 == 20);
	EXPECT_TRUE(cont3 == 30);
	EXPECT_TRUE(head == NULL);
}

TEST(TestFtLstclear, EmptyList) {
	t_list	*head;

	head = NULL;
	ft_lstclear(&head, &DelProto);
	EXPECT_TRUE(head == NULL);
}
