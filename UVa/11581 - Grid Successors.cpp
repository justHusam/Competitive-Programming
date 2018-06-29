#include<bits/stdc++.h>
using namespace std;

char g[5][5], v[5][5];
int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 }, N = 3;

bool calc() {
	int all = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			int sum = 0;
			for (int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && y >= 0 && x < N && y < N)
					sum += g[x][y] == '1';
			}
			sum &= 1;
			v[i][j] = sum + '0';
			all += sum;
		}
	if (all == 0)
		return false;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			g[i][j] = v[i][j];
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int sum = 0, res = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				scanf(" %c", &g[i][j]);
				if (g[i][j] == '1')
					++sum;
			}
		if (sum == 0) {
			puts("-1");
			continue;
		}
		while (calc())
			++res;
		printf("%d\n", res);
	}
	return 0;
}
