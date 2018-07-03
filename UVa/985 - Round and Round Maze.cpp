#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct node {
	bitset<4> msk;
	node() {
		msk.reset();
	}
	node(bitset<4> msk) :
			msk(msk) {
	}
};

bitset<4> get(const bitset<4>&in, int m) {
	bitset<4> bs;
	for (int a = 0; a < 4; ++a) {
		int d = (a + m) % 4;
		bs[d] = in[a];
	}
	return bs;
}

bitset<4> vis[501][501];

int main() {

#ifndef ONLINE_JUDGE
	freopen("read.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif

	int R, C;
	while (scanf("%d%d", &R, &C) > 0) {
		vector<vector<node> > in(R, vector<node>(C));
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) {
				if (i == R - 1 && j == C - 1)
					break;
				char s[6];
				scanf("%s", s);
				int n = strlen(s);
				for (int k = 0; k < n; ++k) {
					int pos;
					switch (s[k]) {
					case 'N':
						pos = 0;
						break;
					case 'E':
						pos = 1;
						break;
					case 'S':
						pos = 2;
						break;
					case 'W':
						pos = 3;
						break;
					}
					in[i][j].msk[pos] = 1;
				}
			}
		queue<pair<int, int> > qu;
		memset(vis, 0, sizeof vis);
		int lev = 0, res = -1;
		qu.push(make_pair(0, 0));
		while (!qu.empty()) {
			int siz = qu.size();
			while (siz-- != 0) {
				pair<int, int> e = qu.front();
				qu.pop();
				for (int i = 0; i < 4; ++i) {
					int tx = e.first + dx[i];
					int ty = e.second + dy[i];
					int tm = lev % 4;
					if (tx < 0 || ty < 0 || tx >= R || ty >= C || vis[tx][ty][tm])
						continue;
					bitset<4> msk = get(in[e.first][e.second].msk, tm);
					if (!msk[i])
						continue;
					if (tx == R - 1 && ty == C - 1) {
						res = lev + 1;
						break;
					}
					vis[tx][ty][tm] = 1;
					qu.push(make_pair(tx, ty));
				}
				if (res != -1)
					break;
			}
			if (res != -1)
				break;
			++lev;
		}
		if (res == -1)
			puts("no path to exit");
		else
			printf("%d\n", res);
	}
	return 0;
}
