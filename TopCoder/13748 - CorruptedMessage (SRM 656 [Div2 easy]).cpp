#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class CorruptedMessage {
public:
	string reconstructMessage(string s, int k) {
		int f[26] = { };
		for (size_t i = 0; i < s.size(); ++i)
			++f[s[i] - 'a'];
		string res = "";
		for (int i = 0; i < 26; ++i) {
			int w = s.length() - f[i];
			if (w == k) {
				res = string(s.length(), i + 'a');
				break;
			}
		}
		return res;
	}
};
