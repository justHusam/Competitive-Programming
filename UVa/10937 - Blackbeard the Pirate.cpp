#include <bits/stdc++.h>
using namespace std;

int n, m, pos[50][50], k, cost[11][11], need[50][50], dp[11][1 << 11];
char g[50][51];
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
bool no[50][50];
pair<int, int> str;
vector<pair<int, int> > v;

void DFS(int x, int y) {
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < n && ty < m)
			no[tx][ty] = true;
	}
}

bool BFS(int src) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			need[i][j] = -1;
	queue<pair<int, int> > qu;
	qu.push(v[src]);
	need[v[src].first][v[src].second] = 0;
	while (!qu.empty()) {
		pair<int, int> fr = qu.front();
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = fr.first + dx[i];
			int ty = fr.second + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || no[tx][ty] || need[tx][ty] != -1)
				continue;
			need[tx][ty] = need[fr.first][fr.second] + 1;
			qu.push(make_pair(tx, ty));
		}
	}
	for (int i = 0; i < k; ++i) {
		if (need[v[i].first][v[i].second] == -1)
			return false;
		cost[src][i] = need[v[i].first][v[i].second];
	}
	return true;
}

int calc(int v, int msk) {
	if (msk == (1 << k) - 1) {
		if (cost[v][0] == -1)
			return 2e9;
		return cost[v][0];
	}
	int &res = dp[v][msk];
	if (res != -1)
		return res;
	res = 2e9;
	for (int i = 0; i < k; ++i)
		if (((msk >> i) & 1) == 0 && cost[v][i] != -1)
			res = min(res, calc(i, msk | (1 << i)) + cost[v][i]);
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		memset(no, false, sizeof no);
		v.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == '@') {
					pos[i][j] = 0;
					str = make_pair(i, j);
				} else if (g[i][j] == '!') {
					v.push_back(make_pair(i, j));
					pos[i][j] = v.size();
				} else if (g[i][j] != '.') {
					no[i][j] = true;
					if (g[i][j] == '*')
						DFS(i, j);
				}
			}
		v.insert(v.begin(), str);
		k = v.size();
		bool can = true;
		for (int i = 0; i < k && can; ++i)
			can &= !no[v[i].first][v[i].second];
		if (!can) {
			puts("-1");
			continue;
		}
		for (int i = 0; i < k && can; ++i)
			can &= BFS(i);
		if (!can) {
			puts("-1");
			continue;
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 1 << 0));
	}
	return 0;
}
