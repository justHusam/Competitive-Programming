#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3;
vector<int> g[N];
int n, m, in[N], level[N];

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && n != 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			level[i] = in[i] = 0;
		}
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			++in[v];
		}
		queue<int> qu;
		for (int i = 0; i < n; ++i)
			if (in[i] == 0)
				qu.push(i);
		int res = 0, lev = 0;
		while (!qu.empty()) {
			int siz = qu.size();
			while (siz--) {
				int v = qu.front();
				qu.pop();
				++level[lev];
				++res;
				for (size_t i = 0; i < g[v].size(); ++i) {
					int u = g[v][i];
					if (--in[u] == 0)
						qu.push(u);
				}
			}
			++lev;
		}
		if (res != n)
			puts("0");
		else {
			int cnt = 1;
			for (int i = 0; i < lev && cnt == 1; ++i)
				if (level[i] > 1)
					cnt = 2;
			printf("%d\n", cnt);
		}
	}
	return 0;
}
