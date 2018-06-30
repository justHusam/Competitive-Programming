#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500;
int n, q;
pair<int, int> seg[N][N << 2];

void update(int p, int l, int r, int at, int v, int T) {
	if (at < l || at > r)
		return;
	if (l == r) {
		seg[T][p] = make_pair(v, v);
		return;
	}
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, at, v, T);
	update(p * 2 + 1, mid + 1, r, at, v, T);
	seg[T][p].first = min(seg[T][p * 2].first, seg[T][p * 2 + 1].first);
	seg[T][p].second = max(seg[T][p * 2].second, seg[T][p * 2 + 1].second);
}

pair<int, int> get(int p, int l, int r, int s, int e, int T) {
	if (l > e || r < s)
		return make_pair(2e9, -2e9);
	if (l >= s && r <= e)
		return seg[T][p];
	int mid = (l + r) >> 1;
	pair<int, int> a = get(p * 2, l, mid, s, e, T);
	pair<int, int> b = get(p * 2 + 1, mid + 1, r, s, e, T);
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			update(1, 0, n - 1, j, x, i);
		}
	scanf("%d", &q);
	while (q-- != 0) {
		char c;
		scanf(" %c", &c);
		if (c == 'q') {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			--x1, --y1;
			--x2, --y2;
			pair<int, int> res = make_pair(2e9, -2e9);
			while (x1 <= x2) {
				pair<int, int> temp = get(1, 0, n - 1, y1, y2, x1);
				res.first = min(res.first, temp.first);
				res.second = max(res.second, temp.second);
				++x1;
			}
			printf("%d %d\n", res.second, res.first);
		} else {
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			update(1, 0, n - 1, --y, c, --x);
		}
	}
	return 0;
}