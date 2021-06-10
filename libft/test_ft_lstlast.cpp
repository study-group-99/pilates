#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtLstlast, Basic) {
	t_list s1, s2, want;
	s1.next = &s2;
	s2.next = &want;
	want.next = NULL;

	t_list *got = ft_lstlast(&s1);
	EXPECT_TRUE(&want == got);
}

TEST(TestFtLstlast, Null) {
	t_list *s;
	s = NULL;
	t_list *got = ft_lstlast(s);
	EXPECT_TRUE(NULL == got);
}

TEST(TestFtLstlast, Basic2) {
	t_list want;
	want.next = NULL;
	
	t_list *got = ft_lstlast(&want);

	EXPECT_TRUE(&want == got);
}
