#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, g[102][102], k;
bool vis[102][102];

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf("%d", &g[i][j]);
				--g[i][j];
			}
		int n1, n2, n3;
		scanf("%d%d%d", &n1, &n2, &n3);
		--n1, --n2, --n3;
		queue<pair<int, int> > qu;
		if (n1 == n3 || n2 == n3) {
			puts("0");
			continue;
		}
		if (n1 >= n || n2 >= n || n3 >= n) {
			puts("-1");
			continue;
		}
		int lev = 1, res = -1;
		qu.push(make_pair(n1, n2));
		memset(vis, false, sizeof vis);
		while (!qu.empty()) {
			int siz = qu.size();
			while (siz-- != 0) {
				int n1 = qu.front().first, n2 = qu.front().second;
				qu.pop();
				if (g[n1][n2] != -1 && !vis[g[n1][n2]][n2]) {
					if (g[n1][n2] == n3) {
						res = lev;
						break;
					}
					vis[g[n1][n2]][n2] = true;
					qu.push(make_pair(g[n1][n2], n2));
				}
				if (g[n2][n1] != -1 && !vis[n1][g[n2][n1]]) {
					if (g[n2][n1] == n3) {
						res = lev;
						break;
					}
					vis[n1][g[n2][n1]] = true;
					qu.push(make_pair(n1, g[n2][n1]));
				}
				if (res != -1)
					break;
			}
			if (res != -1)
				break;
			++lev;
		}
		printf("Game #%d\n", ++k);
		if (res == -1)
			puts("Destination is Not Reachable !\n");
		else
			printf("Minimum Number of Moves = %d\n\n", res);
	}
	return 0;
}
