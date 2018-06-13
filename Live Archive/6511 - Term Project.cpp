#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, low[N], idx[N], id, sz[N], cnt;
vector<int> g[N], st;
bool in[N];

void DFS(int v) {
	low[v] = idx[v] = ++id;
	in[v] = true;
	st.push_back(v);
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
			++sz[cnt];
		} while (n != v);
		++cnt;
	}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			idx[i] = sz[i] = 0;
		}
		int res = n;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			--x;
			if (i == x)
				--res;
			else
				g[i].push_back(x);
		}
		id = cnt = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i);
		for (int i = 0; i < cnt; ++i)
			if (sz[i] > 1)
				res -= sz[i];
		printf("%d\n", res);
	}
	return 0;
}
