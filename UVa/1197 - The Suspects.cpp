#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 30000;
int p[N], sz[N];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void add(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		p[x] = y;
		sz[y] += sz[x];
	}
}

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0 && n != 0) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			sz[i] = 1;
		}
		while (m-- != 0) {
			int q, x, y;
			scanf("%d%d", &q, &x);
			--q;
			while (q-- != 0) {
				scanf("%d", &y);
				add(x, y);
				x = y;
			}
		}
		printf("%d\n", sz[find(0)]);
	}
	return 0;
}
