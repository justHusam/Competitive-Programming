#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3 + 9;
string s;

bool check() {
	int x = 0, y = 0, z = 0;
	for (size_t i = 0; i < s.length(); ++i) {
		if (s[i] == 'A') {
			++x;
			continue;
		}
		if (s[i] == 'B') {
			++y;
			continue;
		}
		if (s[i] == 'C') {
			++z;
			continue;
		}
		if (s[i] == 'a') {
			if (!x)
				return 0;
			--x;
			continue;
		}
		if (s[i] == 'b') {
			if (!y)
				return 0;
			--y;
			continue;
		}
		if (s[i] == 'c') {
			if (!z)
				return 0;
			--z;
			continue;
		}
		return 0;
	}
	if (x != 0 || y != 0 || z != 0)
		return false;
	return true;
}

int main(int argc, char **argv) {
	int t;
	cin >> t;
	cin.ignore();
	while (t-- != 0) {
		getline(cin, s);
		if (check())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
