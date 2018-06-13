#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, m, k;
vector<int> g[N], st;
bool e[N][N], w[N], vis[N];

int DFS(int v) {
	vis[v] = true;
	int sz = 1;
	for (int i = 0; i < (int) g[v].size(); ++i)
		if (!vis[g[v][i]] && w[g[v][i]])
			sz += DFS(g[v][i]);
	return sz;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		scanf("%d%d", &m, &k);
		st.clear();
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			fill(e[i], e[i] + n, false);
			w[i] = true;
			st.push_back(i);
			vis[i] = false;
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			if (e[u][v])
				continue;
			g[u].push_back(v);
			g[v].push_back(u);
			e[u][v] = e[v][u] = true;
		}
		bool update = true;
		while (update) {
			update = false;
			while (!st.empty()) {
				int v = st.back(), can = 0;
				st.pop_back();
				for (size_t i = 0; i < g[v].size(); ++i)
					if (w[g[v][i]])
						++can;
				if (can < k) {
					update = true;
					w[v] = false;
				}
			}
			for (int i = 0; i < n; ++i)
				if (w[i])
					st.push_back(i);
		}
		int res = 0;
		for (size_t i = 0; i < st.size(); ++i)
			if (!vis[st[i]])
				res = max(res, DFS(st[i]));
		printf("%d\n", res);
	}
	return 0;
}
