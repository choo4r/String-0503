#include "gmock/gmock.h"
#include "string.cpp"

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}