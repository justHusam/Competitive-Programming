#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

inline bool check1(char ch) {
	return !(ch == 'o' || ch == 'a' || ch == 'u' || ch == 'i' || ch == 'e');
}

inline bool check2(char ch) {
	return ch == 'o' || ch == 's' || ch == 'x';
}

int main(int argc, char **argv) {
	int n, l;
	while (scanf("%d%d", &l, &n) > 0) {
		map<string, string> hs;
		for (int i = 0; i < l; ++i) {
			char x[25], y[25];
			scanf("%s%s", x, y);
			hs[x] = y;
		}
		for (int i = 0; i < n; ++i) {
			char x[25];
			scanf("%s", x);
			if (hs.find(x) != hs.end()) {
				printf("%s\n", hs[string(x)].c_str());
				continue;
			}
			int n = strlen(x);
			if (n == 1 && check2(x[0])) {
				printf("%ses\n", x);
				continue;
			}
			if (n == 1) {
				printf("%ss\n", x);
				continue;
			}
			if (check1(x[n - 2]) && x[n - 1] == 'y') {
				x[n - 1] = 'i';
				printf("%ses\n", x);
				continue;
			}
			if (check2(x[n - 1])) {
				printf("%ses\n", x);
				continue;
			}
			if (x[n - 2] == 'c' && x[n - 1] == 'h') {
				printf("%ses\n", x);
				continue;
			}
			if (x[n - 2] == 's' && x[n - 1] == 'h') {
				printf("%ses\n", x);
				continue;
			}
			printf("%ss\n", x);
		}
	}
	return 0;
}
