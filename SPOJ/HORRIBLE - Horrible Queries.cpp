#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 2;
int n, q;
ll seg[N << 2], lazy[N << 2];

inline void pro(int p, int l, int r) {
	seg[p] += lazy[p] * (r - l + 1);
	if (l != r) {
		lazy[p * 2] += lazy[p];
		lazy[p * 2 + 1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int p, int l, int r, int s, int e, int v) {
	if (lazy[p] != 0)
		pro(p, l, r);
	if (r < s || l > e)
		return;
	if (l >= s && r <= e) {
		lazy[p] += v;
		pro(p, l, r);
		return;
	}
	int m = (l + r) >> 1;
	update(p * 2, l, m, s, e, v);
	update(p * 2 + 1, m + 1, r, s, e, v);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

ll get(int p, int l, int r, int s, int e) {
	if (lazy[p] != 0)
		pro(p, l, r);
	if (r < s || l > e)
		return 0;
	if (l >= s && r <= e)
		return seg[p];
	int m = (l + r) >> 1;
	return get(p * 2, l, m, s, e) + get(p * 2 + 1, m + 1, r, s, e);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &q);
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);
		while (q-- != 0) {
			int type, s, e, v;
			scanf("%d", &type);
			if (type == 0) {
				scanf("%d%d%d", &s, &e, &v);
				update(1, 1, n, s, e, v);
			} else {
				scanf("%d%d", &s, &e);
				printf("%lld\n", get(1, 1, n, s, e));
			}
		}
	}
	return 0;
}
