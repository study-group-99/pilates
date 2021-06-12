#include <gtest/gtest.h>
#include <stdlib.h>
#include <strings.h>

extern "C" {
#include "../libft.h"
}

void	incrementing(void *content)
{
	*(int *)content += 1;
}

TEST(TestFtLstiter, Basic) {
	t_list got1, got2, got3;
	int cont1 = 1;
	int cont2 = 2;
	int cont3 = 3;

	got1.next = &got2;
	got1.content = &cont1;
	got2.next = &got3;
	got2.content = &cont2;
	got3.next = NULL;
	got3.content = &cont3;

	ft_lstiter(&got1, incrementing);
	EXPECT_EQ(2, *(int *)got1.content);
	EXPECT_EQ(3,*(int *)got2.content);
	EXPECT_EQ(4, *(int *)got3.content);
}

TEST(TestFtLstiter, Basic2) {
	t_list got;
	int cont1 = 1;

	got.next = NULL;
	got.content = &cont1;

	ft_lstiter(&got, incrementing);
	EXPECT_EQ(2, *(int *)got.content);
}

// TEST(TestFtlstiter, MustSegfault) {
// 	EXPECT_EXIT((ft_lstiter(NULL, incrementing), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_lstiter(NULL, lstiter_f);\n";
// }
