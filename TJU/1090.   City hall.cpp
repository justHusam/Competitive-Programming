#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool vis[250][250];
char g[250][250];
int n, m, cnt;

inline void dfs(int x, int y) {
	vis[x][y] = 1;
	if (x + 1 == n || g[x + 1][y] == '1')
		return;
	++cnt;
	dfs(x + 1, y);
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < m; ++b)
			scanf(" %c", &g[a][b]);
	map<int, int> hs;
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < m; ++b)
			if (!vis[a][b] && g[a][b] == '0') {
				cnt = 1;
				dfs(a, b);
				++hs[cnt];
			}
	map<int, int>::iterator it;
	for (it = hs.begin(); it != hs.end(); ++it)
		printf("%d %d\n", it->first, it->second);
	return 0;
}
