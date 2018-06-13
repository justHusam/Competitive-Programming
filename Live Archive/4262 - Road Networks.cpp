#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
vector<int> g[N], st;
int low[N], idx[N], id, res;
bool in[N];

void DFS(int v) {
	in[v] = true;
	st.push_back(v);
	low[v] = idx[v] = ++id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!idx[u]) {
			DFS(u);
			low[v] = min(low[v], low[u]);
		} else if (in[u])
			low[v] = min(low[v], low[u]);
	}
	if (low[v] == idx[v]) {
		int n;
		do {
			n = st.back();
			st.pop_back();
			in[n] = false;
		} while (n != v);
		++res;
	}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear(), idx[i] = 0;
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
		}
		int x;
		scanf("%d", &x);
		res = id = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i);
		printf("%d\n", res);
	}
	return 0;
}
