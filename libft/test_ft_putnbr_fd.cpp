#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtPutnbr_Fd, Basic) {
	testing::internal::CaptureStdout();
	ft_putnbr_fd(0, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(0, atoi(got.c_str())) << "Input: ft_putnbr_fd(0, 1);";
}

TEST(TestFtPutnbr_Fd, Random) {
	int	want = 3453;

	testing::internal::CaptureStdout();
	ft_putnbr_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, atoi(got.c_str())) << "Input: ft_putnbr_fd(3453, 1);";

	want = 986423;
	testing::internal::CaptureStdout();
	ft_putnbr_fd(want, 1);
	got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, atoi(got.c_str())) << "Input: ft_putnbr_fd(986423, 1);";

	want = -612;
	testing::internal::CaptureStdout();
	ft_putnbr_fd(want, 1);
	got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, atoi(got.c_str())) << "Input: ft_putnbr_fd(-612, 1);";

	want = -22788;
	testing::internal::CaptureStdout();
	ft_putnbr_fd(want, 1);
	got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, atoi(got.c_str())) << "Input: ft_putnbr_fd(-22788, 1);";
}

TEST(TestFtPutnbr_Fd, MinInteger) {
	int want = -2147483648LL;

	testing::internal::CaptureStdout();
	ft_putnbr_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, atoi(got.c_str())) << "Input: ft_putnbr_fd(-2147483648LL, 1);";
}

TEST(TestFtPutnbr_Fd, MaxInteger) {
	int want = 2147483647;

	testing::internal::CaptureStdout();
	ft_putnbr_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_EQ(want, atoi(got.c_str())) << "Input: ft_putnbr_fd(2147483647, 1);";
}
