#include <bits/stdc++.h>
using namespace std;

int g[8][8], dr[8][8], res;
bitset<70> bs;
int dx[] = { -1, -1, -1 }, dy[] = { 0, -1, 1 };

bool check(pair<int, int> pos) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 1;; ++j) {
			int tx = pos.first + dx[i] * j;
			int ty = pos.second + dy[i] * j;
			if (tx < 0 || ty < 0 || tx >= 8 || ty >= 8)
				break;
			if (!bs[dr[tx][ty]])
				return false;
		}
	}
	return true;
}

void calc(int pos, int sum) {
	if (pos == 8) {
		res = max(res, sum);
		return;
	}
	for (int i = 0; i < 8; ++i) {
		if (check(make_pair(pos, i))) {
			bs[dr[pos][i]] = 0;
			calc(pos + 1, sum + g[pos][i]);
			bs[dr[pos][i]] = 1;
		}
	}
}

int main(int argc, char **argv) {
	int ID = 0;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			dr[i][j] = ID++;
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				scanf("%d", &g[i][j]);
		bs.set();
		res = 0;
		calc(0, 0);
		printf("%5i\n", res);
	}
	return 0;
}
