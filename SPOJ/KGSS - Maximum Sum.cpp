#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int a, b;
	node() {
		a = b = -1;
	}
	node(int a, int b) :
			a(a), b(b) {
	}
};

const int N = 1e5 + 1;
int n, q, a[N];
node seg[4 * N];

inline node merge(const node &l, const node &r) {
	node res;
	if (l.a > r.a) {
		res.a = l.a;
		if (l.b > r.a)
			res.b = l.b;
		else
			res.b = r.a;
	} else {
		res.a = r.a;
		if (r.b > l.a)
			res.b = r.b;
		else
			res.b = l.a;
	}
	return res;
}

void build(int p, int l, int r) {
	if (l == r) {
		seg[p] = node(a[l], -1);
		return;
	}
	int m = (l + r) >> 1;
	build(p * 2, l, m);
	build(p * 2 + 1, m + 1, r);
	seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
}

void update(int p, int l, int r, int at, int v) {
	if (at < l || at > r)
		return;
	if (l == r) {
		a[at] = v;
		seg[p] = node(a[at], -1);
		return;
	}
	int m = (l + r) >> 1;
	update(p * 2, l, m, at, v);
	update(p * 2 + 1, m + 1, r, at, v);
	seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
}

node get(int p, int l, int r, int s, int e) {
	if (l > e || r < s)
		return node();
	if (l >= s && r <= e)
		return seg[p];
	int m = (l + r) >> 1;
	node L = get(p * 2, l, m, s, e);
	node R = get(p * 2 + 1, m + 1, r, s, e);
	return merge(L, R);
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	build(1, 1, n);
	scanf("%d", &q);
	char t;
	int a, b;
	while (q-- != 0) {
		scanf(" %c%d%d", &t, &a, &b);
		if (t == 'U')
			update(1, 1, n, a, b);
		else {
			node res = get(1, 1, n, a, b);
			printf("%d\n", res.a + res.b);
		}
	}
	return 0;
}
