#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20;
int n, sum, v[N], dp[N][1 << N], dp1[N][200001], vis[N][1 << N], vs, vis1[N][200001], vs1;

int calc(int msk, int i, int w, int bit) {
	if (w == sum)
		return 1;
	if (i == n || w > sum)
		return 0;
	int &res = dp1[i][w];
	if (vis1[i][w] == vs1)
		return res;
	vis1[i][w] = vs1;
	res = calc(msk, i + 1, w, bit);
	if (res == 0 && ((msk >> i) & 1) == bit)
		res = calc(msk, i + 1, w + v[i], bit);
	return res;
}

int calc(int i, int msk, int w) {
	if (w == sum * 2) {
		++vs1;
		if (!calc(msk, 0, 0, 0))
			return 0;
		++vs1;
		return calc(msk, 0, 0, 1);
	}
	if (i == n || w > sum * 2)
		return 0;
	int &res = dp[i][msk];
	if (vis[i][msk] == vs)
		return res;
	vis[i][msk] = vs;
	res = calc(i + 1, msk, w);
	if (res == 0)
		res = calc(i + 1, msk | (1 << i), w + v[i]);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			sum += v[i];
		}
		if (sum % 4 != 0) {
			puts("no");
			continue;
		}
		sum /= 4;
		++vs;
		if (calc(0, 0, 0))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
