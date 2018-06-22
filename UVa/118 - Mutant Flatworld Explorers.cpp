#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[111];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
vector<vector<bool> > vis;

int get(char o) {
	if (o == 'N')
		return 0;
	if (o == 'S')
		return 1;
	if (o == 'E')
		return 2;
	return 3;
}

char left(char o) {
	if (o == 'N')
		return 'W';
	if (o == 'W')
		return 'S';
	if (o == 'S')
		return 'E';
	return 'N';
}

char right(char o) {
	if (o == 'N')
		return 'E';
	if (o == 'E')
		return 'S';
	if (o == 'S')
		return 'W';
	return 'N';
}

int main(int argc, char **argv) {
	int n, m, x, y;
	char o;
	scanf("%d%d", &n, &m);
	vis.resize(n + 1, vector<bool>(m + 1));
	while (scanf("%d%d %c", &x, &y, &o) > 0) {
		scanf("%s", s);
		bool lost = false;
		for (int i = 0; s[i] && !lost; ++i) {
			if (s[i] == 'L')
				o = left(o);
			else if (s[i] == 'R')
				o = right(o);
			else {
				int j = get(o);
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx > n || ty > m) {
					lost = !vis[x][y];
					vis[x][y] = true;
				} else
					x = tx, y = ty;
			}
		}
		if (lost)
			printf("%d %d %c LOST\n", x, y, o);
		else
			printf("%d %d %c\n", x, y, o);
	}
	return 0;
}
