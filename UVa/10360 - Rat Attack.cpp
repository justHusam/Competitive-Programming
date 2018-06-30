#include <bits/stdc++.h>
using namespace std;

const int N = 1025;
int n, d, at[N][N], s[N][N], e[N][N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &d, &n);
		for (int i = 0; i < N; ++i)
			for (int j = i; j < N; ++j)
				s[i][j] = s[j][i] = e[i][j] = e[j][i] = at[i][j] = at[j][i] = 0;
		pair<int, int> mn = make_pair(N, N), mx = make_pair(-1, -1);
		for (int i = 0, x, y, w; i < n; ++i) {
			scanf("%d%d%d", &x, &y, &w);
			int x1 = max(0, x - d);
			int y1 = max(0, y - d);
			int x2 = min(1024, x + d);
			int y2 = min(1024, y + d);
			mn.first = min(mn.first, x1);
			mn.second = min(mn.second, y1);
			mx.first = max(mx.first, x2);
			mx.second = max(mx.second, y2);
			for (int j = x1; j <= x2; ++j) {
				s[j][y1] += w;
				e[j][y2] += w;
			}
		}
		for (int i = mn.first; i <= mx.first; ++i) {
			int add = 0;
			for (int j = mn.second; j <= mx.second; ++j) {
				add += s[i][j];
				at[i][j] += add;
				add -= e[i][j];
			}
		}
		int res = -1, x, y;
		for (int i = mn.first; i <= mx.first; ++i)
			for (int j = mn.second; j <= mx.second; ++j)
				if (at[i][j] > res) {
					res = at[i][j];
					x = i;
					y = j;
				}
		printf("%d %d %d\n", x, y, res);
	}
	return 0;
}
