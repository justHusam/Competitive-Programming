#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, q;
pair<int, int> seg[N << 2];
bool lazy[N << 2];

inline pair<int, int> calc(pair<int, int> a, pair<int, int> b) {
	return make_pair(a.first + b.first, a.second + b.second);
}

inline void build(int p, int l, int r) {
	if (l == r) {
		seg[p] = make_pair(1, 0);
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	seg[p] = calc(seg[p * 2], seg[p * 2 + 1]);
}

inline void pro(int p, int l, int r) {
	swap(seg[p].first, seg[p].second);
	if (l != r) {
		lazy[p * 2] ^= 1;
		lazy[p * 2 + 1] ^= 1;
	}
	lazy[p] = false;
}

void update(int p, int l, int r, int s, int e) {
	if (lazy[p])
		pro(p, l, r);
	if (l > e || r < s)
		return;
	if (l >= s && r <= e) {
		lazy[p] = true;
		pro(p, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, s, e);
	update(p * 2 + 1, mid + 1, r, s, e);
	seg[p] = calc(seg[p * 2], seg[p * 2 + 1]);
}

pair<int, int> get(int p, int l, int r, int s, int e) {
	if (lazy[p])
		pro(p, l, r);
	if (l > e || r < s)
		return make_pair(0, 0);
	if (l >= s && r <= e)
		return seg[p];
	int mid = (l + r) >> 1;
	return calc(get(p * 2, l, mid, s, e), get(p * 2 + 1, mid + 1, r, s, e));
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &q);
	build(1, 0, n - 1);
	while (q-- != 0) {
		int t, s, e;
		scanf("%d%d%d", &t, &s, &e);
		--s;
		--e;
		if (t == 0) {
			update(1, 0, n - 1, s, e);
		} else {
			pair<int, int> res = get(1, 0, n - 1, s, e);
			printf("%d\n", res.second);
		}
	}
	return 0;
}
