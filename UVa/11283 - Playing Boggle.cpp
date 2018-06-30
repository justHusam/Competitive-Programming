#include<bits/stdc++.h>
using namespace std;

int n, dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 }, dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 }, N = 4;
bool vis[4][4];
char s[20], g[6][6];

int get() {
	if (n <= 4)
		return 1;
	if (n == 5)
		return 2;
	if (n == 6)
		return 3;
	if (n == 7)
		return 5;
	return 11;
}

bool DFS(int x, int y, int i) {
	if (i == n)
		return true;
	vis[x][y] = true;
	bool can = false;
	for (int k = 0; k < 8 && !can; ++k) {
		int tx = x + dx[k];
		int ty = y + dy[k];
		if (tx >= 0 && ty >= 0 && tx < N && ty < N && !vis[tx][ty] && g[tx][ty] == s[i])
			can |= DFS(tx, ty, i + 1);
	}
	vis[x][y] = false;
	return can;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf(" %c", &g[i][j]);
		int q, res = 0;
		scanf("%d", &q);
		while (q-- != 0) {
			scanf("%s", s);
			n = strlen(s);
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					if (g[i][j] == s[0] && DFS(i, j, 1)) {
						res += get();
						i = j = N;
					}
		}
		printf("Score for Boggle game #%d: %d\n", k++, res);
	}
	return 0;
}
