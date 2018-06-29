#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, k, x[N], y[N], vis[N], vs, match[N];
vector<int> L, R, g[N];
char s[6];

inline int dist(int i, int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

bool DFS(int v) {
	vis[v] = vs;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = match[g[v][i]];
		if (u == -1 || (vis[u] != vs && DFS(u))) {
			match[g[v][i]] = v;
			return true;
		}
	}
	return false;
}

bool check(int mid) {
	for (int i = 0; i < n; ++i) {
		g[i].clear();
		match[i] = -1;
	}
	for (int i = 0; i < L.size(); ++i)
		for (int j = 0; j < R.size(); ++j)
			if (dist(L[i], R[j]) <= 1LL * mid * mid)
				g[L[i]].push_back(R[j]);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		++vs;
		if (DFS(i))
			++res;
	}
	return res >= k;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &k);
		L.clear();
		R.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%s", &x[i], &y[i], s);
			if (s[0] == 'r')
				L.push_back(i);
			else
				R.push_back(i);
		}
		int l = 1, r = 1e4, res = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				res = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		if (res == -1)
			puts("Impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
