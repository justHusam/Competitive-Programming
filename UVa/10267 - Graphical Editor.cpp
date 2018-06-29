#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 250;
char g[MAX][MAX + 1];
int N, M, vis[MAX][MAX], vs;
queue<pair<int, int> > qu;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
string name;

int main(int argc, char **argv) {
	char type;
	while (cin >> type && type != 'X') {
		if (type == 'I')
			cin >> M >> N;
		if (type == 'C' || type == 'I') {
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					g[i][j] = 'O';
			continue;
		}
		if (type == 'L') {
			int X, Y;
			char C;
			cin >> X >> Y >> C;
			g[Y - 1][X - 1] = C;
			continue;
		}
		if (type == 'V') {
			int X, Y1, Y2;
			char C;
			cin >> X >> Y1 >> Y2 >> C;
			if (Y2 < Y1)
				swap(Y1, Y2);
			for (int i = Y1 - 1; i < Y2; ++i)
				g[i][X - 1] = C;
			continue;
		}
		if (type == 'H') {
			int X1, X2, Y;
			char C;
			cin >> X1 >> X2 >> Y >> C;
			if (X2 < X1)
				swap(X1, X2);
			for (int i = X1 - 1; i < X2; ++i)
				g[Y - 1][i] = C;
			continue;
		}
		if (type == 'K') {
			int X1, Y1, X2, Y2;
			char C;
			cin >> X1 >> Y1 >> X2 >> Y2 >> C;
			if (X2 < X1)
				swap(X1, X2);
			if (Y2 < Y1)
				swap(Y1, Y2);

			for (int i = Y1 - 1; i < Y2; ++i)
				for (int j = X1 - 1; j < X2; ++j)
					g[i][j] = C;
			continue;
		}
		if (type == 'F') {
			int X, Y;
			char C;
			cin >> X >> Y >> C;
			--X, --Y;
			char curCol = g[Y][X];
			vis[Y][X] = ++vs;
			qu.push( { Y, X });
			while (!qu.empty()) {
				int x = qu.front().first, y = qu.front().second;
				qu.pop();
				g[x][y] = C;
				for (int i = 0; i < 4; ++i) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx < 0 || ty < 0 || tx >= N || ty >= M || vis[tx][ty] == vs || g[tx][ty] != curCol)
						continue;
					vis[tx][ty] = vs;
					qu.push( { tx, ty });
				}
			}
			continue;
		}
		if (type == 'S') {
			getchar();
			getline(cin, name);
			puts(name.c_str());
			for (int i = 0; i < N; ++i, puts(""))
				for (int j = 0; j < M; ++j)
					printf("%c", g[i][j]);
			continue;
		}
		getline(cin, name);
	}
	return 0;
}

