#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int n, m, low[N], idx[N], comp[N], id, cnt;
vector<int> g[N], A[N], B[N], all[N], st;
bool in[N];

void DFS(int v) {
	low[v] = idx[v] = ++id;
	st.push_back(v);
	in[v] = true;
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
			comp[n] = cnt;
			all[cnt].push_back(n);
		} while (n != v);
		++cnt;
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			A[i].clear();
			B[i].clear();
			all[i].clear();
			idx[i] = 0;
		}
		while (m-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[b].push_back(a);
		}
		id = cnt = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i);
		bool can = true;
		for (int i = 0; i < n && can; ++i) {
			for (size_t j = 0; j < g[i].size(); ++j)
				if (comp[i] == comp[g[i][j]]) {
					A[i].push_back(g[i][j]);
					B[g[i][j]].push_back(i);
				}
			can &= all[comp[i]].size() != 1;
		}
		for (int i = 0; i < cnt && can; ++i) {
			if (all[i].size() == 2)
				continue;
			for (size_t j = 0; j < all[i].size(); ++j) {
				int v = all[i][j];
				if (A[v].size() == 1 && B[v].size() == 1 && A[v][0] == B[v][0]) {
					can = false;
					break;
				}
			}
		}
		if (can)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
