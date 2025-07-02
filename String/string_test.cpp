#include "gmock/gmock.h"
#include "string.cpp"

using namespace testing;

class stringFixture : public Test {
public:
	Similarity sim;
	StringResult result;

	int  getLenthScore(string str1, string str2) {
		return sim.lengthCheck(str1, str2);
	}

	int getContainScore(string str1, string str2) {
		return sim.containCheck(str1, str2);
	}
};

TEST_F(stringFixture, checkLength)
{
	int expected = 0;
	expected = getLenthScore("ABCD", "DDDD");
	EXPECT_EQ(60, expected);

	expected = getLenthScore("ABCD", "DD");
	EXPECT_EQ(0, expected);

	expected = getLenthScore("ABCDEF", "DDDD");
	EXPECT_EQ(30, expected);

	expected = getLenthScore("ABCD", "DDDDD");
	EXPECT_EQ(45, expected);

	expected = getLenthScore("ABCD", "DDDDDD");
	EXPECT_EQ(30, expected);
}


TEST_F(stringFixture, getContainScore)
{
	int expected = 0;
	expected = getContainScore("AAAB", "AB");
	EXPECT_EQ(40, expected);

	expected = getContainScore("AAAB", "CDEGB");
	EXPECT_EQ(6, expected);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}