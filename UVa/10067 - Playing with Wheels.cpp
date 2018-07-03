#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

struct state {
	int x, y, z, w;
	state() {
	}
	state(int x, int y, int z, int w) :
			x(x), y(y), z(z), w(w) {
	}
	bool operator ==(const state & e) const {
		return x == e.x && y == e.y && z == e.z && w == e.w;
	}
};

bool vis[11][11][11][11];

int m1[] = { 1, -1, 0, 0, 0, 0, 0, 0 };
int m2[] = { 0, 0, 1, -1, 0, 0, 0, 0 };
int m3[] = { 0, 0, 0, 0, 1, -1, 0, 0 };
int m4[] = { 0, 0, 0, 0, 0, 0, 1, -1 };

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		state s, e;
		scanf("%d%d%d%d", &s.x, &s.y, &s.z, &s.w);
		scanf("%d%d%d%d", &e.x, &e.y, &e.z, &e.w);
		int n;
		scanf("%d", &n);
		memset(vis, false, sizeof vis);
		while (n-- != 0) {
			int x, y, z, w;
			scanf("%d%d%d%d", &x, &y, &z, &w);
			vis[x][y][z][w] = true;
		}
		if (vis[s.x][s.y][s.z][s.w] || vis[e.x][e.y][e.z][e.w]) {
			puts("-1");
			continue;
		}
		if (s == e) {
			puts("0");
			continue;
		}
		queue<state> qu;
		qu.push(s);
		int lev = 1, res = -1;
		while (!qu.empty()) {
			int siz = qu.size();
			while (siz-- != 0) {
				state e = qu.front();
				qu.pop();
				int v[4];
				for (int i = 0; i < 8; ++i) {
					v[0] = e.x + m1[i];
					v[1] = e.y + m2[i];
					v[2] = e.z + m3[i];
					v[3] = e.w + m4[i];
					for (int j = 0; j < 4; ++j) {
						if (v[j] > 9)
							v[j] = 0;
						if (v[j] < 0)
							v[j] = 9;
					}
					if (!vis[v[0]][v[1]][v[2]][v[3]]) {
						vis[v[0]][v[1]][v[2]][v[3]] = true;
						if (state(v[0], v[1], v[2], v[3]) == e) {
							res = lev;
							break;
						}
						qu.push(state(v[0], v[1], v[2], v[3]));
					}
					if (!vis[v[0]][v[1]][v[2]][v[3]]) {
						vis[v[0]][v[1]][v[2]][v[3]] = true;
						if (state(v[0], v[1], v[2], v[3]) == e) {
							res = lev;
							break;
						}
						qu.push(state(v[0], v[1], v[2], v[3]));
					}
				}
				if (res != -1)
					break;
			}
			if (res != -1)
				break;
			++lev;
		}
		printf("%d\n", res);
	}
	return 0;
}
