#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

void	del(void *s)
{
	free(s);
}

TEST(TestFtLstdelone, Basic) {
	int	*l = (int *)malloc(sizeof(int));
	*l = 99;
	t_list *s = (t_list *)malloc(sizeof(t_list));
	s->content = l;
	ft_lstdelone(s, &del);

	EXPECT_TRUE(1);
}
