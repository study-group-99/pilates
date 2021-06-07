#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

// t_list	*cpy_Tlist_elem(t_list *elem)
// {
// 	t_list	*result;

// 	result = ft_lstnew(elem->content);
// 	return (result);
// }

// TEST(TestFtLstmap, CheckThreeElem) {
// 	t_list e1, e2, e3;
// 	t_list *result;
// 	int cont1 = 1;
// 	int cont2 = 2;
// 	int cont3 = 3;

// 	e1.next = &e2;
// 	e1.content = &cont1;
// 	e2.next = &e3;
// 	e2.content = &cont2;
// 	e3.next = NULL;
// 	e3.content = &cont3;

// 	result = ft_lstmap(&e1, &cpy_Tlist_elem);
// 	ASSERT_TRUE(result != NULL);
// 	EXPECT_TRUE(result->content == &cont1);
// 	EXPECT_TRUE(result->next->content == &cont2);
// 	EXPECT_TRUE(result->next->next->content == &cont3);
// 	EXPECT_TRUE(result->next->next->next == NULL);

// 	free(result->next->next);
// 	free(result->next);
// 	free(result);
// }
