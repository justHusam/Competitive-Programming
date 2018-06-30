#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int O = 2500;
int N, n, m, a[100], vis[100][50][5001], vs, dp[100][50][5001], all;

int calcMX(int at, int w, int sum) {
	if (N - at + w < n)
		return -2e9;
	if (w == n)
		return sum * (all - sum);
	int &res = dp[at][w][sum + O];
	if (vis[at][w][sum + O] == vs)
		return res;
	vis[at][w][sum + O] = vs;
	return res = max(calcMX(at + 1, w, sum), calcMX(at + 1, w + 1, sum + a[at]));
}

int calcMN(int at, int w, int sum) {
	if (N - at + w < n)
		return 2e9;
	if (w == n)
		return sum * (all - sum);
	int &res = dp[at][w][sum + O];
	if (vis[at][w][sum + O] == vs)
		return res;
	vis[at][w][sum + O] = vs;
	return res = min(calcMN(at + 1, w, sum), calcMN(at + 1, w + 1, sum + a[at]));
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) != EOF) {
		all = 0;
		N = n + m;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &a[i]);
			all += a[i];
		}
		if (m < n)
			swap(n, m);
		++vs;
		int mx = calcMX(0, 0, 0);
		++vs;
		int mn = calcMN(0, 0, 0);
		printf("%d %d\n", mx, mn);
	}
	return 0;
}