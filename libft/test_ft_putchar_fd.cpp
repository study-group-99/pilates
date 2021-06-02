#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
}

TEST(TestFtPutchar_Fd, PutCharIntoFile) {
	char	out = 'a';
	char	in;
	int		fdo;
	int		fdi;
	int		i;

	i = 0;
	fdo = open("temp_file_to_test_putchar_fd.txt", O_CREAT|O_RDWR|O_TRUNC, 0666);
	if (fdo != -1)
	{
		ft_putchar_fd(out, fdo);
		close(fdo);
	}
	fdi = open("temp_file_to_test_putchar_fd.txt", O_RDWR);
	if (fdi != -1)
	{
		i = read(fdi, &in, 1);
		close(fdi);
		remove("temp_file_to_test_putchar_fd.txt");
	}
	EXPECT_EQ(out, in);
	EXPECT_EQ(1, i);
}
