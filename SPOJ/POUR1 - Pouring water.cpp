#include <bits/stdc++.h>
using namespace std;

bool vis[40001][4];

int BFS(int A, int B, int C) {
	queue<pair<int, int> > qu;
	memset(vis, false, sizeof vis);
	int levels = 1;
	if (C == 0)
		return 0;
	if (C > A && C > B)
		return -1;
	if (C == A || C == B)
		return 1;
	qu.push(make_pair(0, 0));
	while (!qu.empty()) {
		int siz = qu.size();
		while (siz-- != 0) {
			pair<int, int> e = qu.front();
			qu.pop();
			// empty A
			if (!vis[e.second][0]) {
				vis[e.second][0] = true;
				qu.push(make_pair(0, e.second));
			}
			// empty B
			if (!vis[e.first][1]) {
				vis[e.first][1] = true;
				qu.push(make_pair(e.first, 0));
			}
			// fill A
			if (!vis[e.second][2]) {
				vis[e.second][2] = true;
				qu.push(make_pair(A, e.second));
			}
			// fill B
			if (!vis[e.first][3]) {
				vis[e.first][3] = true;
				qu.push(make_pair(e.first, B));
			}
			int P, F, S;
			// pour A --> B
			P = min(e.first, B - e.second);
			F = e.first - P;
			S = e.second + P;
			if (F == C || S == C)
				return levels;
			if (F == 0) {
				if (!vis[S][0]) {
					vis[S][0] = true;
					qu.push(make_pair(F, S));
				}
			} else {
				if (!vis[F][3]) {
					vis[F][3] = true;
					qu.push(make_pair(F, S));
				}
			}
			// pour B --> A
			P = min(e.second, A - e.first);
			F = e.first + P;
			S = e.second - P;
			if (F == C || S == C)
				return levels;
			if (S == 0) {
				if (!vis[F][1]) {
					vis[F][1] = true;
					qu.push(make_pair(F, S));
				}
			} else {
				if (!vis[S][2]) {
					vis[S][2] = true;
					qu.push(make_pair(F, S));
				}
			}
		}
		++levels;
	}
	return -1;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", BFS(a, b, c));
	}
	return 0;
}

