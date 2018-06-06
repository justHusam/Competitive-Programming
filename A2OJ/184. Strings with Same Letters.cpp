#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3 + 9;
char x[N], y[N];

int main(int argc, char **argv) {
	int T = 1;
	while (scanf("%s%s", x, y) && !isupper(x[0])) {
		int n = strlen(x), m = strlen(y);
		int f[30] = { }, s[30] = { };
		for (int i = 0; i < n; ++i)
			++f[x[i] - 'a'];
		for (int i = 0; i < m; ++i)
			++s[y[i] - 'a'];
		bool can = true;
		for (int i = 0; i < 26 && can; ++i)
			if (f[i] != s[i])
				can = false;
		printf("Case %d: ", T++);
		if (can)
			puts("same");
		else
			puts("different");
	}
	return 0;
}
