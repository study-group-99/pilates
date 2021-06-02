#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

char test_function(unsigned int move_ascii, char c)
{
	return (c + move_ascii);
}

TEST(TestFtStrmapi, SimpleStr) {
	char arr[] = "ABCD";
	char arr_expected[] = "ACEG";
	char *result;

	result = ft_strmapi(arr, &test_function);
	ASSERT_TRUE(result != NULL);
	EXPECT_EQ(0, strcmp(result, arr_expected));
	// free(result);
}

char	mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

TEST(TestFtStrmapi, SimpleStrWarTest) {
	char	*str;
	char	*strmapi;

	alarm(5);
	str = (char *)malloc(sizeof(*str) * 12);
	strcpy(str, "LoReM iPsUm");
	strmapi = ft_strmapi(str, &mapi);

	ASSERT_TRUE(strmapi != NULL);
	ASSERT_STREQ("lOrEm IpSuM", strmapi);
}

TEST(TestFtStrmapi, EmptyStr) {
	char arr[] = "";
	char arr_expected[] = "";
	char *result;

	result = ft_strmapi(arr, &test_function);
	ASSERT_TRUE(result != NULL);
	EXPECT_EQ(0, strcmp(result, arr_expected));
	// free(result);
}
