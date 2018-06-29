#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1 << 20;
int h, k, n, a[N], dp[N][21], vis[N][21], vs;

int calc(int p, int k) {
	if (p * 2 >= n)
		return a[p];
	int &res = dp[p][k];
	if (vis[p][k] == vs)
		return res;
	vis[p][k] = vs;
	res = a[p];
	for (int i = 1; i < k; ++i)
		res = max(res, calc(p * 2, i) + calc(p * 2 + 1, k - i));
	return res;
}

void get(int n, int w) {
	scanf("%d", &a[n]);
	if (w == h)
		return;
	get(n * 2, w + 1);
	get(n * 2 + 1, w + 1);
}

int main(int argc, char **argv) {
	while (scanf("%d", &h) > 0 && h != -1) {
		scanf("%d", &k);
		get(1, 0);
		n = 1 << (h + 1);
		++vs;
		printf("%d\n", calc(1, k));
	}
	return 0;
}
