#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstadd_front, CheckOfSizeT) {
	t_list example1;
	t_list newOne;
	t_list *head;
	int var = 99;
	char c = 'X';

	example1.content = &var;
	newOne.content = &c;
	head = &example1;
	ft_lstadd_front(&head, &newOne);
	EXPECT_TRUE(newOne.next == &example1);
	EXPECT_TRUE(head == &newOne);
	EXPECT_TRUE(*(char*)head->content == 'X');
	EXPECT_TRUE(*(int*)head->next->content == 99);
}
