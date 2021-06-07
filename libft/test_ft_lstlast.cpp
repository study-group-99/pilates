#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstlast, CheckThreeElem) {
	t_list e1, e2, e3;
	e1.next = &e2;
	e2.next = &e3;
	e3.next = NULL;
	t_list	*result;

	result = ft_lstlast(&e1);
	EXPECT_TRUE(result == &e3);
}

TEST(TestFtLstlast, CheckNull) {
	t_list *ptr;
	ptr = NULL;
	t_list	*result;

	result = ft_lstlast(ptr);
	EXPECT_TRUE(result == NULL);
}

TEST(TestFtLstlast, CheckOneElem) {
	t_list e1;
	e1.next = NULL;
	t_list	*result;

	result = ft_lstlast(&e1);
	EXPECT_TRUE(result == &e1);
}
