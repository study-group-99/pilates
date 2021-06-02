#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}


TEST(TestFtLstsize, CheckThreeElem) {
	t_list e1, e2, e3;
	e1.next = &e2;
	e2.next = &e3;
	e3.next = NULL;
	int	result;

	result = ft_lstsize(&e1);
	EXPECT_TRUE(result == 3);
}

TEST(TestFtLstsize, CheckNull) {
	t_list *ptr;
	ptr = NULL;
	int	result;

	result = ft_lstsize(ptr);
	EXPECT_TRUE(result == 0);
}

TEST(TestFtLstsize, CheckOneElem) {
	t_list e1;
	e1.next = NULL;
	int	result;

	result = ft_lstsize(&e1);
	EXPECT_TRUE(result == 1);
}
