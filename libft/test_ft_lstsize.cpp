#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}


TEST(TestFtLstsize, Basic) {
	t_list e1, e2, e3;
	e1.next = &e2;
	e2.next = &e3;
	e3.next = NULL;
	int got = ft_lstsize(&e1);
	
	EXPECT_EQ(3, got);
}

TEST(TestFtLstsize, Null) {
	t_list *s;
	s = NULL;
	int got = ft_lstsize(s);

	EXPECT_EQ(NULL, got);
}

TEST(TestFtLstsize, Basic2) {
	t_list e1;
	e1.next = NULL;
	int got = ft_lstsize(&e1);
	
	EXPECT_EQ(1, got);
}
