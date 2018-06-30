#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline bool check(string &s, int M) {
	int mod = 0;
	for (int i = 0; i < (int) s.size(); ++i)
		mod = (mod * 10 + (s[i] - '0')) % M;
	return mod == 0;
}

int main(int argc, char **argv) {
	int cas = 0;
	string s;
	while (cin >> s) {
		if (cas++ != 0)
			puts("");
		bool ord = true, leep = false;
		if (check(s, 400) || (check(s, 4) && !check(s, 100))) {
			puts("This is leap year.");
			leep = true;
			ord = false;
		}
		if (check(s, 15)) {
			puts("This is huluculu festival year.");
			ord = false;
		}
		if (leep && check(s, 55)) {
			puts("This is bulukulu festival year.");
			ord = false;
		}
		if (ord)
			puts("This is an ordinary year.");
	}
	return 0;
}