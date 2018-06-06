#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e5;
int n, g[N], m;

bool check(int v) {
	int with = 0, in = 1;
	for (int i = 1; i < n; ++i) {
		with += g[i] - g[i - 1];
		if (with >= v)
			with = 0, ++in;
		if (in == m)
			return true;
	}
	return false;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d", g + i);
		sort(g, g + n);
		int l = 1, r = g[n - 1] + 1, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m)) {
				l = m + 1;
				res = m;
			} else
				r = m - 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
