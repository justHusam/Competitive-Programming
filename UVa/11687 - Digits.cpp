#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
char s[N];

inline int calc(int x) {
	int res = 0;
	while (x != 0) {
		++res;
		x /= 10;
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0 && s[0] != 'E') {
		if (!strcmp(s, "1")) {
			puts("1");
			continue;
		}
		int x0 = strlen(s), res;
		for (int i = 2;; ++i) {
			int x1 = calc(x0);
			if (x1 == x0) {
				res = i;
				break;
			}
			x0 = x1;
		}
		printf("%d\n", res);
	}
	return 0;
}
