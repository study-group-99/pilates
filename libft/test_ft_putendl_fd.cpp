#include <gtest/gtest.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtPutendl_Fd, Basic) {
	char want[] = "this is a test";

	testing::internal::CaptureStdout();
	ft_putendl_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(want, got.erase(strlen(want)).c_str()) << "Input: ft_putendl_fd(\"this is a test\", 1);";
}

TEST(TestFtPutendl_Fd, Ascii) {
	char want[] = "string \x01 of \x63 non \x0a ascii \x12 chars\x1d";

	testing::internal::CaptureStdout();
	ft_putendl_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(want, got.erase(strlen(want)).c_str()) << "Input: ft_putendl_fd(\"string \\x01 of \\x63 non \\x0a ascii \\x12 chars\\x1d\", 1);";
}

TEST(TestFtPutendl_Fd, NonAscii) {
	char want[] = "γειά σου ντέιβ";

	testing::internal::CaptureStdout();
	ft_putendl_fd(want, 1);
	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(want, got.erase(strlen(want)).c_str()) << "Input: ft_putendl_fd(\"γειά σου ντέιβ\", 1);";
}

TEST(TestFtPutendl_Fd, MustSegfault) {
	EXPECT_EXIT((ft_putendl_fd(NULL, 1), exit(0)),::testing::KilledBySignal(SIGSEGV),".*") << "Input: ft_putendl_fd(NULL, 1);\n";
}
