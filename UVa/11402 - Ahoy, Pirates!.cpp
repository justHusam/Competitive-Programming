#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1024000;
int n, a[N], m, q, seg[N << 2], lazy[N << 2];
char z[51];

void build(int p, int l, int r) {
	if (l == r) {
		seg[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

inline void pro(int p, int l, int r) {
	if (lazy[p] < 2) {
		seg[p] = (r - l + 1) * lazy[p];
		if (l != r)
			lazy[p * 2] = lazy[p * 2 + 1] = lazy[p];
	} else {
		seg[p] = (r - l + 1) - seg[p];
		if (l != r) {
			if (lazy[p * 2] == 0 || lazy[p * 2] == 1)
				lazy[p * 2] ^= 1;
			else if (lazy[p * 2] == 2)
				lazy[p * 2] = -1;
			else if (lazy[p * 2] == -1)
				lazy[p * 2] = 2;
			if (lazy[p * 2 + 1] == 0 || lazy[p * 2 + 1] == 1)
				lazy[p * 2 + 1] ^= 1;
			else if (lazy[p * 2 + 1] == 2)
				lazy[p * 2 + 1] = -1;
			else if (lazy[p * 2 + 1] == -1)
				lazy[p * 2 + 1] = 2;
		}
	}
	lazy[p] = -1;
}

void update(int p, int l, int r, int s, int e, int type) {
	if (lazy[p] != -1)
		pro(p, l, r);
	if (l > e || r < s)
		return;
	if (l >= s && r <= e) {
		lazy[p] = type;
		pro(p, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, s, e, type);
	update(p * 2 + 1, mid + 1, r, s, e, type);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

int get(int p, int l, int r, int s, int e) {
	if (lazy[p] != -1)
		pro(p, l, r);
	if (l > e || r < s)
		return 0;
	if (l >= s && r <= e)
		return seg[p];
	int mid = (l + r) >> 1;
	return get(p * 2, l, mid, s, e) + get(p * 2 + 1, mid + 1, r, s, e);
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &m);
		n = 0;
		for (int i = 0, x; i < m; ++i) {
			scanf("%d%s", &x, z);
			while (x--)
				for (int j = 0; z[j]; ++j)
					a[n++] = z[j] - '0';
		}
		memset(lazy, -1, sizeof lazy);
		build(1, 0, n - 1);
		scanf("%d", &q);
		printf("Case %d:\n", cas++);
		for (int Q = 1; q != 0; --q) {
			char ch;
			int s, e;
			scanf(" %c%d%d", &ch, &s, &e);
			if (ch == 'F')
				update(1, 0, n - 1, s, e, 1);
			else if (ch == 'E')
				update(1, 0, n - 1, s, e, 0);
			else if (ch == 'I')
				update(1, 0, n - 1, s, e, 2);
			else
				printf("Q%d: %d\n", Q++, get(1, 0, n - 1, s, e));
		}
	}
	return 0;
}
