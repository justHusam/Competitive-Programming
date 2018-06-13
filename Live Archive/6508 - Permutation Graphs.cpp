#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n, a[N][2], seg[4 * N], pos[N][2];

void build(int p, int l, int r) {
	if (l == r) {
		seg[p] = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(p * 2, l, m);
	build(p * 2 + 1, m + 1, r);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

void update(int p, int l, int r, int at) {
	if (at < l || at > r)
		return;
	if (l == r) {
		--seg[p];
		return;
	}
	int m = (l + r) >> 1;
	update(p * 2, l, m, at);
	update(p * 2 + 1, m + 1, r, at);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

int get(int p, int l, int r, int s, int e) {
	if (l > e || r < s)
		return 0;
	if (l >= s && r <= e)
		return seg[p];
	int m = (l + r) >> 1;
	return get(p * 2, l, m, s, e) + get(p * 2 + 1, m + 1, r, s, e);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int j = 0; j < 2; ++j)
			for (int i = 1; i <= n; ++i) {
				scanf("%d", &a[i][j]);
				pos[a[i][j]][j] = i;
			}
		build(1, 1, n);
		ll res = 0;
		for (int i = 1; i <= n; ++i) {
			int e = pos[a[i][0]][1];
			if (e != 1)
				res += get(1, 1, n, 1, e - 1);
			update(1, 1, n, e);
		}
		printf("%lld\n", res);
	}
	return 0;
}
