#include <stdexcept>
#include <string>
#include <cmath>
#include <set>

using namespace std;
using std::set;

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

	double containCheck(const string& str1, const string& str2) {
		set<char> alphabets = getAlphabets(str1 + str2);
		int totalcnt = alphabets.size();

		int samecnt = 0;
		for (char ch : alphabets) {
			if (str1.find(ch) == string::npos) continue;
			if (str2.find(ch) == string::npos) continue;
			samecnt++;
		}

		return (double)samecnt / (double)totalcnt * 40;
	}

	set<char> getAlphabets(const string& str) {
		set<char> alphabets;
		for (char ch : str)
			alphabets.insert(ch);
		return alphabets;
	}

};