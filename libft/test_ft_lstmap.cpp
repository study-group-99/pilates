#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

void *lstmap_f(void *content) {
	return ((void *)"OK !");
}

TEST(TestFtLstmap, Basic) {
	t_list e1, e2, e3;
	char cont1[] = "test";
	char cont2[] = "nuhhh";
	char cont3[] = "^^^555";

	e1.next = &e2;
	e1.content = &cont1;
	e2.next = &e3;
	e2.content = &cont2;
	e3.next = NULL;
	e3.content = &cont3;

	t_list *result = ft_lstmap(&e1, lstmap_f, NULL);
	EXPECT_STREQ("OK !", (char *)result->content);
	EXPECT_STREQ("OK !", (char *)result->next->content);
	EXPECT_STREQ("OK !", (char *)result->next->next->content);
	EXPECT_EQ(NULL, result->next->next->next);
}
