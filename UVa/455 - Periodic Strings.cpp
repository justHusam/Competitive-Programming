#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

string s;

inline bool check(int len) {
	if (s.length() % len != 0)
		return false;
	string temp = s.substr(0, len);
	for (size_t i = len; i < s.size(); i += len)
		if (s.substr(i, len) != temp)
			return false;
	return true;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	while (T-- != 0) {
		cin >> s;
		int res = -1;
		for (size_t i = 1; i <= s.size(); ++i)
			if (check(i)) {
				res = i;
				break;
			}
		printf("%d\n", res);
		if (T != 0)
			puts("");
	}
	return 0;
}
