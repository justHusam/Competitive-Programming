#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n, q, a[N], seg[4 * N];
set<int> z;

void build(int p, int l, int r) {
	if (l == r) {
		seg[p] = a[l] < 0;
		return;
	}
	int m = (l + r) >> 1;
	build(p * 2, l, m);
	build(p * 2 + 1, m + 1, r);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

void update(int p, int l, int r, int at, int v) {
	if (at < l || at > r)
		return;
	if (l == r) {
		a[at] = v;
		seg[p] = a[at] < 0;
		return;
	}
	int m = (l + r) >> 1;
	update(p * 2, l, m, at, v);
	update(p * 2 + 1, m + 1, r, at, v);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

int get(int p, int l, int r, int s, int e) {
	if (r < s || l > e)
		return 0;
	if (l >= s && r <= e)
		return seg[p];
	int m = (l + r) >> 1;
	return get(p * 2, l, m, s, e) + get(p * 2 + 1, m + 1, r, s, e);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &q) > 0) {
		z.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] == 0)
				z.insert(i);
		}
		build(1, 1, n);
		char t;
		int x, y;
		while (q-- != 0) {
			scanf(" %c%d%d", &t, &x, &y);
			if (t == 'C') {
				if ((a[x] == 0 && y == 0) || (a[x] > 0 && y > 0) || (a[x] < 0 && y < 0))
					continue;
				if (y == 0) {
					z.insert(x);
					a[x] = y;
				} else {
					if (a[x] == 0)
						z.erase(x);
					update(1, 1, n, x, y);
				}
			} else {
				set<int>::iterator it = z.lower_bound(x);
				if (it != z.end() && *it >= x && *it <= y) {
					putchar('0');
					continue;
				}
				int v = get(1, 1, n, x, y);
				if (v & 1)
					putchar('-');
				else
					putchar('+');
			}
		}
		puts("");
	}
	return 0;
}
