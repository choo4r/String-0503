#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

struct StringResult {
	int score = 0;
	int result = 0;
};

class Similarity {
public:
	int lengthCheck(const string& str1, const string& str2) {
		int gab = std::abs(((int)str1.length() - (int)str2.length()));
		int denominator = std::min(str1.length(), str2.length());

		return (1 - ((double)gab / (double)denominator)) * 60;
	}

	void assertIllegalArgument(const string& inputString)
	{
		for (char ch : inputString) {
			if (ch >= 'A' && ch <= 'Z') continue;
			throw invalid_argument("Must be uppercase letter");
		}
	}
};