#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 80001;
int n, a[N], seg[4 * N];
vector<int> hs;

int get(int p, int l, int r, int s, int e) {
	if (l > r || r < s)
		return 2e9;
	if (l >= s && r <= e)
		return seg[p];
	int m = (l + r) >> 1;
	return min(get(p * 2, l, m, s, e), get(p * 2 + 1, m + 1, r, s, e));
}

void update(int p, int l, int r, int at, int v) {
	if (at < l || at > r)
		return;
	if (l == r) {
		seg[p] = min(seg[p], v);
		return;
	}
	int m = (l + r) >> 1;
	update(p * 2, l, m, at, v);
	update(p * 2 + 1, m + 1, r, at, v);
	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		hs.push_back(a[i]);
	}
	sort(hs.begin(), hs.end());
	hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
	for (int i = 0; i < n; ++i)
		a[i] = lower_bound(hs.begin(), hs.end(), a[i]) - hs.begin() + 1;
	int sz = hs.size();
	for (int i = sz * 4; i >= 0; --i)
		seg[i] = 2e9;
	ll res = 0;
	for (int i = n - 1; i >= 0; --i) {
		int e = get(1, 1, sz, a[i], sz);
		if (e == 2e9)
			e = n;
		res += e - i - 1;
		update(1, 1, sz, a[i], i);
	}
	printf("%lld\n", res);
	return 0;
}
