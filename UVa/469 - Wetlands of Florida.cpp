#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int R, C;
vector<string> g;
string line;

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < R && y < C && g[x][y] == 'W';
}

int BFS(pair<int, int> pos) {
	vector<vector<bool> > vis(R, vector<bool>(C, 0));
	int res = 1;
	pair<int, int> temp;
	queue<pair<int, int> > qu;
	vis[pos.first][pos.second] = true;
	qu.push(pos);
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();
		for (int i = 0; i < 8; ++i) {
			int tx = temp.first + dx[i];
			int ty = temp.second + dy[i];
			if (check(tx, ty) && !vis[tx][ty]) {
				++res;
				vis[tx][ty] = true;
				qu.push(make_pair(tx, ty));
			}
		}
	}
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		g.clear();
		while (getline(cin, line)) {
			if (!isalpha(line[0]))
				break;
			g.push_back(line);
		}
		R = g.size();
		C = g[0].size();
		do {
			int i, j;
			stringstream ss(line);
			ss >> i;
			ss >> j;
			printf("%d\n", BFS(make_pair(i - 1, j - 1)));
		} while (getline(cin, line) && line != "");
		if (T != 0)
			puts("");
	}
	return 0;
}
