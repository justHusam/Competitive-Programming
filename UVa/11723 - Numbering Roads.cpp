#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

inline int calc(int n, int r) {
	for (int i = 0; i <= 26; ++i) {
		int with = r + r * i;
		if (with >= n)
			return i;
	}
	return -1;
}

int main(int argc, char **argv) {
	int k = 1, n, r;
	while (scanf("%d%d", &n, &r) > 0 && n + r > 0) {
		int res = calc(n, r);
		printf("Case %d: ", k++);
		if (res == -1)
			puts("impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
