#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<vector<int> > > dp;
int n, m, sz;
vector<int> v;

int calc(int at, int w, int d) {
	if (at == n || d == m)
		return 0;
	int &res = dp[at][w][d];
	if (res != -1)
		return res;
	res = calc(at + 1, w, d);
	res = max(res, calc(at, 0, d + 1));
	if (w + v[at] < sz)
		res = max(res, calc(at + 1, w + v[at], d) + 1);
	else if (w + v[at] == sz)
		res = max(res, calc(at + 1, 0, d + 1) + 1);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &sz, &m);
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d,", &v[i]);
		dp.clear();
		dp.resize(n);
		for (int i = 0; i < n; ++i)
			dp[i].resize(sz, vector<int>(m, -1));
		printf("%d\n", calc(0, 0, 0));
		if (t != 0)
			puts("");
	}
	return 0;
}
