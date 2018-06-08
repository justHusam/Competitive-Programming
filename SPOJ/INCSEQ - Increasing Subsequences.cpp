#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4, M = 5e6;
int n, a[N], k, BIT[51][100001], dp[N][51], mx;

inline void add(int &sum, int val) {
	sum += val;
	if (sum >= M)
		sum -= M;
}

inline void add(int idx, int val, int *BIT) {
	while (idx <= mx) {
		add(BIT[idx], val);
		idx += idx & -idx;
	}
}

inline int get(int idx, int *BIT) {
	int res = 0;
	while (idx != 0) {
		add(res, BIT[idx]);
		idx -= idx & -idx;
	}
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= k; ++j) {
			if (j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = get(a[i] - 1, BIT[j - 1]);
			add(a[i], dp[i][j], BIT[j]);
		}
	int res = 0;
	for (int i = 0; i < n; ++i)
		add(res, dp[i][k]);
	printf("%d\n", res);
	return 0;
}

