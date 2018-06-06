#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	cin >> T;
	while (T-- != 0) {
		int n, p = 0;
		cin >> n;
		cin.ignore();
		string s;
		getline(cin, s);
		vector<vector<char> > g(n, vector<char>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				g[i][j] = s[p++];
				if (p == (int) s.length()) {
					p = 0;
					s = "*";
				}
			}
		for (int i = 1; i <= n; ++i) {
			int l = 0, r = i - 1;
			for (int j = 0; j < i; ++j)
				putchar(g[l++][r--]);
		}
		for (int i = 1; i < n; ++i) {
			int l = i, r = n - 1;
			while (r != -1 && l != n)
				putchar(g[l++][r--]);
		}
		puts("");
	}
	return 0;
}
