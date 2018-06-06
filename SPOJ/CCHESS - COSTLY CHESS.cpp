#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
pair<int, int> str, dest;

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int dijkstra(pair<int, int> str, pair<int, int> ed) {
	priority_queue<pair<int, pair<int, int> > > qu;
	bool vis[8][8] = { };
	int tx, ty, ct;
	qu.push(make_pair(0, str));
	while (!qu.empty()) {
		pair<int, pair<int, int> > temp = qu.top();
		qu.pop();
		if (temp.second == ed)
			return temp.first * -1;
		if (vis[temp.second.first][temp.second.second])
			continue;
		vis[temp.second.first][temp.second.second] = true;
		for (int i = 0; i < 8; ++i) {
			int tx = temp.second.first + dx[i];
			int ty = temp.second.second + dy[i];
			if (!check(tx, ty) || vis[tx][ty])
				continue;
			ct = temp.first * -1 + temp.second.first * tx + temp.second.second * ty;
			qu.push(make_pair(ct * -1, make_pair(tx, ty)));
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d%d", &str.first, &str.second, &dest.first, &dest.second) > 0) {
		printf("%d\n", dijkstra(str, dest));
	}
	return 0;
}
