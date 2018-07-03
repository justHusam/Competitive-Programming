#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

char get(int d) {
	if (d == 0)
		return 'N';
	if (d == 1)
		return 'E';
	if (d == 2)
		return 'S';
	return 'W';
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int R, C;
		scanf("%d%d", &R, &C);
		vector<vector<char> > g(R, vector<char>(C));
		for (int i = 0; i < R; ++i) {
			getchar();
			for (int j = 0; j < C; ++j)
				g[i][j] = getchar();
		}
		int x, y, d = 0;
		scanf("%d%d", &x, &y);
		--x, --y;
		vector<string> v;
		string s;
		getchar();
		while (getline(cin, s) && !s.empty())
			v.push_back(s);
		bool done = false;
		for (size_t i = 0; i < v.size() && !done; ++i)
			for (size_t j = 0; j < v[i].size() && !done; ++j) {
				if (v[i][j] == 'R')
					if (++d > 3)
						d = 0;
				if (v[i][j] == 'L')
					if (--d < 0)
						d = 3;
				if (v[i][j] == 'F') {
					int tx = x + dx[d];
					int ty = y + dy[d];
					if (tx >= 0 && ty >= 0 && tx < R && ty < C && g[tx][ty] != '*') {
						x = tx;
						y = ty;
					}
				}
				if (v[i][j] == 'Q')
					done = true;
			}
		printf("%d %d %c\n", x + 1, y + 1, get(d));
		if (T != 0)
			puts("");
	}
	return 0;
}
