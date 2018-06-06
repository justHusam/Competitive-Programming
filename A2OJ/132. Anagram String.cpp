#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e4 + 1;
char f[N], s[N];

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 1) {
		scanf("%s%s", f, s);
		int hs1[27] = { }, hs2[27] = { };
		int n = strlen(f);
		int m = strlen(s);
		for (int a = 0; a < n; ++a)
			++hs1[f[a] - 'a'];
		for (int a = 0; a < m; ++a)
			++hs2[s[a] - 'a'];
		int res = 0;
		for (int a = 0; a < 26; ++a)
			res += abs(hs1[a] - hs2[a]);
		printf("%d\n", res);
	}
	return 0;
}
