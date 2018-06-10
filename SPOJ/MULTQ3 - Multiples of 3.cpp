#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n, q, seg[4 * N][3], lazy[4 * N];

void build(int p, int l, int r) {
	if (l == r) {
		++seg[p][0];
		return;
	}
	int m = (l + r) >> 1;
	build(p * 2, l, m);
	build(p * 2 + 1, m + 1, r);
	seg[p][0] = seg[p * 2][0] + seg[p * 2 + 1][0];
}

inline void pro(int p, int l, int r) {
	int m = lazy[p] % 3;
	if (m == 1) {
		int v = seg[p][2];
		seg[p][2] = seg[p][1];
		seg[p][1] = seg[p][0];
		seg[p][0] = v;
	} else if (m == 2) {
		int v = seg[p][0];
		seg[p][0] = seg[p][1];
		seg[p][1] = seg[p][2];
		seg[p][2] = v;
	}
	if (l != r) {
		lazy[p * 2] += lazy[p];
		lazy[p * 2 + 1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int p, int l, int r, int s, int e) {
	if (lazy[p] != 0)
		pro(p, l, r);
	if (l > e || r < s)
		return;
	if (l >= s && r <= e) {
		++lazy[p];
		pro(p, l, r);
		return;
	}
	int m = (l + r) >> 1;
	update(p * 2, l, m, s, e);
	update(p * 2 + 1, m + 1, r, s, e);
	for (int i = 0; i < 3; ++i)
		seg[p][i] = seg[p * 2][i] + seg[p * 2 + 1][i];
}

int get(int p, int l, int r, int s, int e) {
	if (lazy[p] != 0)
		pro(p, l, r);
	if (l > e || r < s)
		return 0;
	if (l >= s && r <= e)
		return seg[p][0];
	int m = (l + r) >> 1;
	return get(p * 2, l, m, s, e) + get(p * 2 + 1, m + 1, r, s, e);
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	while (q-- != 0) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		++a;
		++b;
		if (t == 0)
			update(1, 1, n, a, b);
		else
			printf("%d\n", get(1, 1, n, a, b));
	}
	return 0;
}
