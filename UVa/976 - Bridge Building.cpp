#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001, oo = 1e9;
int n, m, b, e, type[N][N], cost[N], dp[N][100];
char g[N][N];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

void DFS(int x, int y, int T) {
	type[x][y] = T;
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < n && ty < m && type[tx][ty] == -1 && g[tx][ty] == '#')
			DFS(tx, ty, T);
	}
}

int calc(int at, int ok) {
	if (ok == b)
		return 0;
	if (at >= m)
		return oo;
	int &res = dp[at][ok];
	if (res != -1)
		return res;
	res = oo;
	res = min(res, calc(at + 1, ok));
	res = min(res, calc(at + 1 + e, ok + 1) + cost[at]);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d%d", &n, &m, &b, &e) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		memset(type, -1, sizeof type);
		memset(dp, -1, sizeof dp);
		DFS(0, 0, 0);
		DFS(n - 1, m - 1, 1);
		for (int j = 0; j < m; ++j) {
			cost[j] = oo;
			int last = -1;
			for (int i = n - 1; i >= 0; --i)
				if (g[i][j] == '#') {
					if (last != -1 && i + 1 != last && type[last][j] != type[i][j])
						cost[j] = min(cost[j], last - i - 1);
					last = i;
				}
		}
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
