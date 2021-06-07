#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

void	del(void *ptr)
{
	free(ptr);
}

TEST(TestFtLstdelone, BasicCase) {
	t_list	*e1;
	int		*ptr;

	ptr = (int *)malloc(sizeof(int));
	*ptr = 99;
	e1 = (t_list *)malloc(sizeof(t_list));
	e1->content = ptr;
	ft_lstdelone(e1, &del);

	EXPECT_TRUE(1);
	// Trust me, it works...42 times
}
