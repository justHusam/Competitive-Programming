#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e5 + 9;
char s[N];
int p[N];

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0 && s[0] != '*') {
		int n = strlen(s), k = 0;
		for (int i = 1; i < n; ++i) {
			while (k > 0 && s[k] != s[i])
				k = p[k - 1];
			if (s[i] == s[k])
				p[i] = ++k;
			else
				p[i] = k;
		}
		int res = 1;
		if (n % (n - p[n - 1]) == 0)
			res = n / (n - p[n - 1]);
		printf("%d\n", res);
	}
	return 0;
}
