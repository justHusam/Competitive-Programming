#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool calc(const string &s) {
	vector<int> v;
	for (int i = 0; i < 3; ++i)
		v.push_back(s[i] - '0');
	if (v[0] + 1 == v[1] && v[1] + 1 == v[2])
		return false;
	if (v[0] - 1 == v[1] && v[1] - 1 == v[2])
		return false;
	return true;
}

bool check(const string &s) {
	map<char, int> hs;
	for (size_t i = 0; i < s.length(); ++i)
		++hs[s[i]];
	map<char, int>::iterator it;
	for (it = hs.begin(); it != hs.end(); ++it)
		if (it->second >= 3)
			return false;
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		if (i + 3 > n)
			break;
		string t = s.substr(i, 3);
		if (!calc(t))
			return false;
	}
	return true;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	while (T-- != 0) {
		string s;
		cin >> s;
		if (check(s))
			puts("ACCEPTABLE");
		else
			puts("WEAK");
	}
	return 0;
}
