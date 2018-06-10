#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e6 + 9;
char s[N];
int n, P[N];

int main(int argc, char **argv) {
	int T, it = 1;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%s", &n, s);
		memset(P, 0, sizeof P);
		for (int i = 1, k = 0; i < n; ++i) {
			while (k > 0 && s[k] != s[i])
				k = P[k - 1];
			if (s[k] == s[i])
				++k;
			P[i] = k;
		}
		printf("Test case #%d\n", it++);
		for (int i = 1; i < n; ++i) {
			int l = i + 1;
			if (l % (l - P[l - 1]) != 0 || l / (l - P[l - 1]) <= 1)
				continue;
			printf("%d %d\n", l, l / (l - P[l - 1]));
		}
		puts("");
	}
	return 0;
}
