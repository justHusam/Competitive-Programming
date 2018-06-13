#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
vector<int> g[N];
int n, m, res[N], col[N], best, no[N];

void calc(int v, int b, int w) {
	if (w >= n - best)
		return;
	if (v == n) {
		if (b <= best)
			return;
		best = b;
		for (int i = 0; i < n; ++i)
			res[i] = col[i];
		return;
	}
	for (int i = 0; i < 2; ++i) {
		bool can = true;
		if (i != 0)
			for (size_t i = 0; i < g[v].size() && can; ++i)
				can &= col[g[v][i]] != 1;
		if (can) {
			col[v] = i;
			calc(v + 1, b + i, w + !i);
		}
	}
	col[v] = -1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	memset(col, -1, sizeof col);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		best = -1;
		calc(0, 0, 0);
		vector<int> sol;
		for (int i = 0; i < n; ++i)
			if (res[i] != 0)
				sol.push_back(i + 1);
		printf("%d\n", (int) sol.size());
		for (size_t i = 0; i < sol.size(); ++i)
			printf("%s%d", i ? " " : "", sol[i]);
		puts("");
	}
	return 0;
}
