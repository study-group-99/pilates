#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstback, AddAtEndOfThreeElem) {
	t_list e1, e2, e3, last;
	e1.next = &e2;
	e2.next = &e3;
	e3.next = NULL;
	t_list	*head;

	head = &e1;
	ft_lstadd_back(&head, &last);
	EXPECT_TRUE(e3.next == &last);
}

TEST(TestFtLstback, CheckNull) {
	t_list *ptr;
	ptr = NULL;
	t_list	last;

	ft_lstadd_back(&ptr, &last);
	EXPECT_TRUE(ptr == &last);
}

TEST(TestFtLstback, CheckDoubleNull) {
	t_list *ptr, *last;
	ptr = NULL;
	last = NULL;

	ft_lstadd_back(&ptr, last);
	EXPECT_TRUE(ptr == NULL);
}

TEST(TestFtLstback, CheckOneElem) {
	t_list e1, last;
	e1.next = NULL;
	t_list	*head;

	head = &e1;
	ft_lstadd_back(&head, &last);
	EXPECT_TRUE(head->next == &last);
}
