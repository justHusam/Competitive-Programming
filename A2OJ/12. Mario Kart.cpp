#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100, oo = 2e9;
int n, m, mx, pos[N], c[N], v[N], dp[N][1000];
vector<int> g[N];
bool vis[N];

int calc(int i, int p) {
	if (p == 0)
		return 0;
	if (i == m || p < 0)
		return oo;
	int &res = dp[i][p];
	if (res != -1)
		return res;
	return res = min(calc(i + 1, p), calc(i + 1, p - v[i]) + c[i]);
}

int BFS(int src, int dest) {
	queue<int> qu;
	qu.push(src);
	vis[src] = true;
	int lev = 1;
	while (!qu.empty()) {
		int siz = qu.size();
		while (siz-- != 0) {
			int v = qu.front();
			qu.pop();
			for (size_t i = 0; i < g[v].size(); ++i) {
				int u = g[v][i];
				if (vis[u])
					continue;
				if (u == dest)
					return lev;
				vis[u] = true;
				qu.push(u);
			}
		}
		++lev;
	}
	return -1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &n, &m, &mx);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &pos[i]);
			g[i].clear();
			vis[i] = false;
		}
		for (int i = 0; i < m; ++i)
			scanf("%d%d", &c[i], &v[i]);
		sort(pos, pos + n);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				int mn = calc(0, pos[j] - pos[i]);
				if (mn <= mx) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		printf("%d\n", BFS(0, n - 1));
	}
	return 0;
}
