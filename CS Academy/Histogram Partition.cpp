#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, a[N], L[N], R[N], dp[N][19];

int calc(int l, int r) {
	int log = 0;
	while ((1 << log) <= r - l + 1)
		++log;
	--log;
	if (a[dp[l][log]] > a[dp[r - (1 << log) + 1][log]])
		return dp[r - (1 << log) + 1][log];
	return dp[l][log];
}

int calc(int l, int r, int ok) {
	if (l > r)
		return 0;
	int res = 0;
	int mn = calc(l, r);
	if (a[mn] > ok)
		++res;
	int ll = L[mn];
	int rr = R[mn];
	if (ll >= l)
		res += calc(l, ll, a[mn]);
	if (rr <= r)
		res += calc(rr, r, a[mn]);
	return res;
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		if (i != 0 && a[i] == a[i - 1])
			L[i] = L[i - 1];
		else
			L[i] = i - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (i + 1 != n && a[i] == a[i + 1])
			R[i] = R[i + 1];
		else
			R[i] = i + 1;
	}
	for (int i = 0; i < n; ++i)
		dp[i][0] = i;
	for (int j = 1; (1 << j) < n; ++j)
		for (int i = 0; i + (1 << j) <= n; ++i)
			if (a[dp[i][j - 1]] > a[dp[i + (1 << (j - 1))][j - 1]])
				dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
			else
				dp[i][j] = dp[i][j - 1];
	int res = calc(0, n - 1, 0);
	printf("%d\n", res);
	return 0;
}
