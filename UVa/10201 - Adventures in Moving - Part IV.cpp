#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int oo = 2e9;
int n, cost[10001], dp[102][201];
char s[1111];
vector<int> v;

int calc(int i, int w) {
	if (v[i] == n) {
		int need = max(0, 100 - w);
		if (need && cost[n] == oo)
			return oo;
		return need * cost[n];
	}
	int &res = dp[i][w];
	if (res != -1)
		return res;
	res = oo;
	int dist = v[i + 1] - v[i];
	if (dist <= w)
		res = min(res, calc(i + 1, w - dist));
	if (cost[v[i]] != oo) {
		int mn = max(1, dist - w);
		for (int j = mn; w + j <= 200; ++j)
			res = min(res, calc(i + 1, w + j - dist) + cost[v[i]] * j);
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i <= n; ++i)
			cost[i] = oo;
		v.clear();
		getchar();
		v.push_back(0);
		while (gets(s) > 0 && strlen(s)) {
			stringstream ss(s);
			int x, y;
			ss >> x >> y;
			cost[x] = min(cost[x], y);
			if (x != v.back())
				v.push_back(x);
		}
		if (n != v.back())
			v.push_back(n);
		memset(dp, -1, sizeof dp);
		int res = calc(0, 100);
		if (res == oo)
			puts("Impossible");
		else
			printf("%d\n", res);
		if (t != 0)
			puts("");
	}
	return 0;
}
