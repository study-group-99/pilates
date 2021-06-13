#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtPutStr_Fd, Basic) {
	char want[] = "this is a test";

	testing::internal::CaptureStdout();
	ft_putstr_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(want, got.c_str()) << "Input: ft_putstr_fd(\"this is a test\", 1)";
}

TEST(TestFtPutStr_Fd, Ascii) {
	char want[] = "string \x01 of \x63 non \x0a ascii \x12 chars\x1d";

	testing::internal::CaptureStdout();
	ft_putstr_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(want, got.c_str()) << "Input: ft_putstr_fd(\"string \\x01 of \\x63 non \\x0a ascii \\x12 chars\\x1d\", 1);";
}

TEST(TestFtPutStr_Fd, NonAscii) {
	char want[] = "よくやった";

	testing::internal::CaptureStdout();
	ft_putstr_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(want, got.c_str()) << "Input: ft_putstr_fd( \"よくやった\", 1);";
}
