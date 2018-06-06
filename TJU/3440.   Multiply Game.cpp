#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 50001, M = 1000000007;
int n, a[N];
ll seg[N * 4];

void build(int n, int l, int r) {
	if (l == r) {
		seg[n] = a[l];
		return;
	}
	build(n * 2, l, (l + r) / 2);
	build(n * 2 + 1, (l + r) / 2 + 1, r);
	seg[n] = (seg[n * 2] * seg[n * 2 + 1]) % M;
}

int at, val;
void update(int n, int l, int r) {
	if (at < l || at > r)
		return;
	if (l == r) {
		a[at] = seg[n] = val;
		return;
	}
	update(n * 2, l, (l + r) / 2);
	update(n * 2 + 1, (l + r) / 2 + 1, r);
	seg[n] = (seg[n * 2] * seg[n * 2 + 1]) % M;
}

int s, e;
ll get(int n, int l, int r) {
	if (r < s || l > e)
		return 1;
	if (l >= s && r <= e)
		return seg[n];
	return (get(n * 2, l, (l + r) / 2) * get(n * 2 + 1, (l + r) / 2 + 1, r)) % M;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		build(1, 1, n);
		int q;
		scanf("%d", &q);
		while (q-- != 0) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (a == 0) {
				s = b;
				e = c;
				printf("%lld\n", get(1, 1, n));
			} else {
				at = b;
				val = c;
				update(1, 1, n);
			}
		}
	}
	return 0;
}
