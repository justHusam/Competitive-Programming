#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int n, k = 1;
	while (scanf("%d", &n) > 0) {
		map<string, int> hs;
		char x[123], y[123];
		vector<string> p;
		for (int i = 0; i < n; ++i) {
			scanf("%s", x);
			hs[x] = i;
			p.push_back(x);
		}
		int m;
		scanf("%d", &m);
		vector<int> in(n, 0);
		vector<vector<int> > g(n);
		while (m-- != 0) {
			scanf("%s%s", x, y);
			int u = hs[string(x)], v = hs[string(y)];
			++in[v];
			g[u].push_back(v);
		}
		priority_queue<int> qu;
		for (int i = 0; i < n; ++i)
			if (in[i] == 0)
				qu.push(-i);
		vector<int> res;
		while (!qu.empty()) {
			int v = qu.top();
			qu.pop();
			v *= -1;
			res.push_back(v);
			for (size_t i = 0; i < g[v].size(); ++i) {
				int u = g[v][i];
				if (--in[u] == 0)
					qu.push(-u);
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", k++);
		for (size_t i = 0; i < res.size(); ++i)
			printf(" %s", p[res[i]].c_str());
		puts(".\n");
	}
	return 0;
}
