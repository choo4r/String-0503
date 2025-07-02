#include <string>
#include <cmath>
#include <iostream>

using std::string;

class Similarity {
public:
	int lengthCheck(const string& str1, const string& str2) {
		int gab = std::abs(((int)str1.length() - (int)str2.length()));
		int denominator = std::min(str1.length(), str2.length());

		return (1 - ((double)gab / (double)denominator)) * 60;
	}
};