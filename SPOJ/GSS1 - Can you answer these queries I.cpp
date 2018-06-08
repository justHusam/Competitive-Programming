#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int pre, suf, sum, best;
	node() {
		pre = suf = sum = best = -2e9;
	}
	node(int pre, int suf, int sum, int best) :
			pre(pre), suf(suf), sum(sum), best(best) {
	}
};

const int N = 50000;
int n, a[N], q;
node seg[N << 2];

inline node merge(node L, node R) {
	node res;
	res.sum = L.sum + R.sum;
	res.pre = max(L.pre, L.sum + R.pre);
	res.suf = max(R.suf, R.sum + L.suf);
	res.best = max(max(L.best, R.best), max(res.sum, L.suf + R.pre));
	return res;
}

void build(int p, int l, int r) {
	if (l == r) {
		seg[p] = node(a[l], a[l], a[l], a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
}

node get(int p, int l, int r, int s, int e) {
	if (l >= s && r <= e)
		return seg[p];
	int mid = (l + r) >> 1;
	if (e <= mid)
		return get(p * 2, l, mid, s, e);
	if (s > mid)
		return get(p * 2 + 1, mid + 1, r, s, e);
	return merge(get(p * 2, l, mid, s, e), get(p * 2 + 1, mid + 1, r, s, e));
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	build(1, 0, n - 1);
	scanf("%d", &q);
	while (q--) {
		int s, e;
		scanf("%d%d", &s, &e);
		--s;
		--e;
		node res = get(1, 0, n - 1, s, e);
		printf("%d\n", res.best);
	}
	return 0;
}
