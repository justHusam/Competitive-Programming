#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x, y, n;
char s[130];
int vis[64][64];
int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };

int calc(int at, char ch) {
	if (at == 0 && ch == 'R')
		return 1;
	if (at == 0 && ch == 'L')
		return 2;
	if (at == 1 && ch == 'R')
		return 3;
	if (at == 1 && ch == 'L')
		return 0;
	if (at == 2 && ch == 'R')
		return 0;
	if (at == 2 && ch == 'L')
		return 3;
	if (at == 3 && ch == 'R')
		return 2;
	return 1;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%s", &x, &y, s);
		n = strlen(s);
		memset(vis, 0, sizeof vis);
		++vis[x][y];
		int at = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'F') {
				x += dx[at];
				y += dy[at];
				++vis[x][y];
				continue;
			}
			at = calc(at, s[i]);
		}
		int c = 0;
		for (int i = 0; i < 64; ++i)
			for (int j = 0; j < 64; ++j)
				if (vis[i][j] > 1)
					++c;
		printf("Case #%d: %d %d %d\n", cas++, x, y, c);
	}
	return 0;
}
