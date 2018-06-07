#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Q {
	int l, r, idx;
} q[200000];

int n, a[30000], m, k, res[200000], freq[1000001];

bool cmp(Q &a, Q &b) {
	if (a.l / k != b.l / k)
		return a.l / k < b.l / k;
	return a.r < b.r;
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	k = sqrt(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &q[i].l, &q[i].r);
		--q[i].l;
		--q[i].r;
		q[i].idx = i;
	}
	sort(q, q + m, cmp);
	int curL = 0, curR = 0, d = 0;
	for (int i = 0; i < m; ++i) {
		int l = q[i].l, r = q[i].r;
		for (int j = curL; j < l; ++j) {
			if (freq[a[j]] == 1)
				--d;
			--freq[a[j]];
		}
		for (int j = curL - 1; j >= l; --j) {
			if (freq[a[j]] == 0)
				++d;
			++freq[a[j]];
		}
		curL = l;
		for (int j = curR; j <= r; ++j) {
			if (freq[a[j]] == 0)
				++d;
			++freq[a[j]];
		}
		for (int j = curR - 1; j > r; --j) {
			if (freq[a[j]] == 1)
				--d;
			--freq[a[j]];
		}
		curR = r + 1;
		res[q[i].idx] = d;
	}
	for (int i = 0; i < m; ++i)
		printf("%d\n", res[i]);
	return 0;
}
