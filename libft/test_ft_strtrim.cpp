#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrtrim, SimpleTrim) {
    char s[] = "This text is long";

    char *got = ft_strtrim(s, " ighlnoTs");
    EXPECT_STREQ("text", got) << "Input: char *got = ft_strtrim(\"This text is long\", \" ighlnoTs\");";

    got = ft_strtrim(s, "This ");
    EXPECT_STREQ("text is long", got) << "Input: char *got = ft_strtrim(\"text\", \"This \");";

    got = ft_strtrim(s, "long ");
    EXPECT_STREQ("This text is", got) << "Input: char *got = ft_strtrim(\"This text is\", \"long \");";
}

TEST(TestFtStrtrim, TrimZeroStr) {
    char *got = ft_strtrim("", "abcd ");
    EXPECT_STREQ("", got) << "Input: char *got = ft_strtrim(\"\", \"abcd \");";
}

TEST(TestFtStrtrim, TrimEverything) {
    char *got = ft_strtrim("This text is long", " eighlnotTsx");
    EXPECT_STREQ("", got) << "Input: char *got = ft_strtrim(\"This text is long\", \" eighlnotTsx\");";
}

TEST(TestFtStrtrim, TrimNothing) {
    char want[] = "This text is long";

    char *got = ft_strtrim(want, " abd");
    EXPECT_STREQ(want, got) << "Input: char *got = ft_strtrim(\"This text is long\", \" abd\");";
}

TEST(TestFtStrtrim, Empty) {
	char *got = ft_strtrim("", " \n\t");
	EXPECT_STREQ("", got) << "Input: char *got = ft_strtrim(\"\", \" \\n\\t\");";
}

TEST(TestFtStrtrim, EmptyInput) {
	char *got = ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t");
	EXPECT_STREQ("", got) << "Input: char *got = ft_strtrim(\"  \\t \\t \\n   \\n\\n\\n\\t\", \" \\n\\t\");";
}

TEST(TestFtStrtrim, Memory) {
	char *got = ft_strtrim("   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ", " \n\t");
	EXPECT_STREQ("Hello \t  Please\n Trim me !", got) << "Input: char *got = ft_strtrim(\"   \\t  \\n\\n \\t\\t  \\n\\n\\nHello \\t  Please\\n Trim me !\\n   \\n \\n \\t\\t\\n  \", \" \\n\\t\");";
}
