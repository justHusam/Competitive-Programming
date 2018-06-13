#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 50;
int n, m, dp[N][N];
bool vis[N][N];
vector<vector<int> > g;
char x[1000], y[1000];

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &n, &m) && n > 0) {
		g.clear();
		g.resize(n);
		map<string, int> hs;
		int ID = 0;
		while (m-- != 0) {
			scanf("%s%s", x, y);
			if (hs.find(string(x)) == hs.end())
				hs[string(x)] = ID++;
			if (hs.find(string(y)) == hs.end())
				hs[string(y)] = ID++;
			int u = hs[string(x)], v = hs[string(y)];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(vis, false, sizeof vis);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; ++i) {
			queue<int> qu;
			vis[i][i] = true;
			dp[i][i] = 0;
			qu.push(i);
			int lev = 1;
			while (!qu.empty()) {
				int siz = qu.size();
				while (siz-- != 0) {
					int u = qu.front();
					qu.pop();
					for (size_t j = 0; j < g[u].size(); ++j) {
						int v = g[u][j];
						if (vis[i][v])
							continue;
						vis[i][v] = true;
						dp[i][v] = lev;
						qu.push(v);
					}
				}
				++lev;
			}
		}
		bool bad = false;
		for (int i = 0; i < n; ++i)
			if (dp[0][i] == -1) {
				bad = true;
				break;
			}
		printf("Network %d: ", cas++);
		if (bad) {
			puts("DISCONNECTED\n");
			continue;
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				res = max(res, dp[i][j]);
		printf("%d\n\n", res);
	}
	return 0;
}
