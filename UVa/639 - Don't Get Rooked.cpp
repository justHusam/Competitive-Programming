#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n, vis[5][5], id;
char g[5][5];
pair<int, int> dr[16], v[16];
int res;

void calc(int with) {
	int N = n * n, ID = 0;
	bitset<16> msk = with;
	if (msk.count() <= res)
		return;
	++id;
	for (int i = 0; i < N; ++i) {
		if (!msk[i])
			continue;
		if (g[dr[i].first][dr[i].second] == 'X')
			return;
		vis[dr[i].first][dr[i].second] = id;
		v[ID++] = dr[i];
	}
	if (ID <= res)
		return;
	int dx[] = { 0, 1 };
	int dy[] = { 1, 0 };
	for (int i = 0; i < ID; ++i)
		for (int j = 0; j < 2; ++j)
			for (int c = 1;; ++c) {
				int tx = v[i].first + dx[j] * c;
				int ty = v[i].second + dy[j] * c;
				if (tx >= n || ty >= n || g[tx][ty] == 'X')
					break;
				if (vis[tx][ty] == id)
					return;
			}
	res = ID;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		int dest = (1 << (n * n)), ID = 0;
		for (int i = 0; i < n; ++i) {
			getchar();
			for (int j = 0; j < n; ++j) {
				g[i][j] = getchar();
				dr[ID++] = make_pair(i, j);
			}
		}
		res = 0;
		for (int i = 1; i < dest; ++i)
			calc(i);
		printf("%d\n", res);
	}
	return 0;
}
