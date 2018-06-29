#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e4;
int row[N], col[N], id, R, C, n, k, r, c;
int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };

bool check() {
	for (int i = 0; i < 5; ++i) {
		int x = r + dx[i];
		int y = c + dy[i];
		if (x >= 0 && y >= 0 && x < R && y < C && row[x] != id && col[y] != id)
			return true;
	}
	return false;
}

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &R, &C, &n) > 0 && R != 0) {
		++id;
		while (n-- != 0) {
			int x, y;
			scanf("%d%d", &x, &y);
			row[x] = col[y] = id;
		}
		scanf("%d%d", &r, &c);
		printf("Case %d: ", ++k);
		if (check())
			puts("Escaped again! More 2D grid problems!");
		else
			puts("Party time! Let's find a restaurant!");
	}
	return 0;
}
