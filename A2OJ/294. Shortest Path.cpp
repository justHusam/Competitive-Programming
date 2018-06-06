#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, str, lev[2005];
vector<int> g[2005];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &str);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				char ch;
				scanf(" %c", &ch);
				if (ch == '1')
					g[i].push_back(j);
			}
		--str;
		queue<int> qu;
		memset(lev, -1, sizeof lev);
		lev[str] = 0;
		qu.push(str);
		while (!qu.empty()) {
			const int fr = qu.front();
			qu.pop();
			for (size_t i = 0; i < g[fr].size(); ++i) {
				int u = g[fr][i];
				if (lev[u] == -1) {
					lev[u] = lev[fr] + 1;
					qu.push(u);
				}
			}
		}
		printf("%d", lev[0]);
		for (int i = 1; i < n; ++i)
			printf(" %d", lev[i]);
		puts("");
	}
	return 0;
}
