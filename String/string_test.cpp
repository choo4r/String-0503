#include "gmock/gmock.h"
#include "string.cpp"

using namespace testing;

class stringFixture : public Test {
public:
	Similarity sim;

};

TEST(string, checkLength)
{
	Similarity sim;
	int expected = sim.lengthCheck("ABCD", "DDDD");
	EXPECT_EQ(60, expected);

	expected = sim.lengthCheck("ABCD", "BB");
	EXPECT_EQ(0, expected);

	expected = sim.lengthCheck("ABCD", "AAA");
	EXPECT_EQ(40, expected);

	expected = sim.lengthCheck("ABCD", "AAAAAA");
	EXPECT_EQ(45, expected);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}