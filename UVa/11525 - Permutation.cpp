#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e4 + 1;
int n, a[N], sol[N], BIT[N];

inline void add(int idx, int val) {
	while (idx <= n) {
		BIT[idx] += val;
		idx += idx & -idx;
	}
}

inline void add(int l, int r, int val) {
	add(l, val);
	add(r + 1, -val);
}

inline int get(int idx) {
	int res = 0;
	while (idx != 0) {
		res += BIT[idx];
		idx -= idx & -idx;
	}
	return res;
}

int BS(int v) {
	int l = 1, r = n, res;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int val = get(mid);
		if (val >= v) {
			res = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	add(res, n, -1);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		memset(BIT, 0, sizeof BIT);
		for (int i = 1; i <= n; ++i)
			add(i, n, 1);
		for (int i = 0; i < n; ++i)
			sol[i] = BS(a[i] + 1);
		for (int i = 0; i < n; ++i)
			printf("%s%d", i ? " " : "", sol[i]);
		puts("");
	}
	return 0;
}
