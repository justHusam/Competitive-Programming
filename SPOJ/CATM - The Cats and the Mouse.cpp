#include <bits/stdc++.h>
using namespace std;

int n, m, T;
pair<int, int> mouse, fCat, sCat;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void BFS(pair<int, int> pos, vector<vector<int> >&cost) {
	queue<pair<int, int>> qu;
	qu.push(pos);
	cost[pos.first][pos.second] = 0;
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = temp.first + dx[i];
			int ty = temp.second + dy[i];
			if (!check(tx, ty) || cost[tx][ty] != -1)
				continue;
			qu.push(make_pair(tx, ty));
			cost[tx][ty] = cost[temp.first][temp.second] + 1;
		}
	}
}

int main(int argc, char **argv) {
	scanf("%d%d%d", &n, &m, &T);
	while (T-- != 0) {
		scanf("%d%d", &mouse.first, &mouse.second);
		scanf("%d%d", &fCat.first, &fCat.second);
		scanf("%d%d", &sCat.first, &sCat.second);
		vector<vector<int> > costM(n, vector<int>(m, -1));
		vector<vector<int> > costF(n, vector<int>(m, -1));
		vector<vector<int> > costS(n, vector<int>(m, -1));
		BFS(make_pair(fCat.first - 1, fCat.second - 1), costF);
		BFS(make_pair(sCat.first - 1, sCat.second - 1), costS);
		BFS(make_pair(mouse.first - 1, mouse.second - 1), costM);
		bool ok = false;
		for (int j = 0; j < m; ++j) {
			if (costM[0][j] < costF[0][j] && costM[0][j] < costS[0][j]) {
				ok = true;
				break;
			}
			if (costM[n - 1][j] < costF[n - 1][j] && costM[n - 1][j] < costS[n - 1][j]) {
				ok = true;
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (costM[i][0] < costF[i][0] && costM[i][0] < costS[i][0]) {
				ok = true;
				break;
			}
			if (costM[i][m - 1] < costF[i][m - 1] && costM[i][m - 1] < costS[i][m - 1]) {
				ok = true;
				break;
			}
		}
		if (ok)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
