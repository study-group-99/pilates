#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}


TEST(TestFtPutchar_Fd, Character) {
	char want = 'a';

	testing::internal::CaptureStdout();
	ft_putchar_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, *got.c_str()) << "Input: ft_putchar_fd('a', 1);";
}

TEST(TestFtPutchar_Fd, Integer) {
	char want = 8;

	testing::internal::CaptureStdout();
	ft_putchar_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, *got.c_str()) << "Input: ft_putchar_fd(8, 1);";
}
