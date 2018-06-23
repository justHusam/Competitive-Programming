#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

char g[22][22];
int n, vis[22][22];
set<string> res[401];
string s;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

inline void DFS(int x, int y) {
	vis[x][y] = 1;
	s += g[x][y];
	if (s.length() >= 3)
		res[s.length() - 1].insert(s);
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= n || vis[tx][ty])
			continue;
		if (g[tx][ty] > s[s.length() - 1])
			DFS(tx, ty);
	}
	vis[x][y] = 0;
	s.erase(s.length() - 1);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		for (int i = 0; i < n * n; ++i)
			res[i].clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				DFS(i, j);
		set<string>::iterator it;
		for (int i = 0; i < n * n; ++i)
			for (it = res[i].begin(); it != res[i].end(); ++it)
				cout << *it << "\n";
		if (T != 0)
			puts("");
	}
	return 0;
}
