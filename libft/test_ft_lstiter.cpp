#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

// void	Incrementing(t_list *elem)
// {
// 	*(int *)elem->content *= 2;
// }

// TEST(TestFtLstiter, CheckThreeElem) {
// 	t_list e1, e2, e3;
// 	int cont1 = 1;
// 	int cont2 = 2;
// 	int cont3 = 3;

// 	e1.next = &e2;
// 	e1.content = &cont1;
// 	e2.next = &e3;
// 	e2.content = &cont2;
// 	e3.next = NULL;
// 	e3.content = &cont3;

// 	ft_lstiter(&e1, &Incrementing);
// 	EXPECT_TRUE(*(int *)e1.content == 2);
// 	EXPECT_TRUE(*(int *)e2.content == 4);
// 	EXPECT_TRUE(*(int *)e3.content == 6);
// }

// TEST(TestFtLstiter, CheckOneElem) {
// 	t_list e1;
// 	int cont1 = 1;

// 	e1.next = NULL;
// 	e1.content = &cont1;

// 	ft_lstiter(&e1, &Incrementing);
// 	EXPECT_TRUE(*(int *)e1.content == 2);
// }
