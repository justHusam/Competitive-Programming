#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 400;
int n, m, low[N], idx[N], comp[N], src[N], dfs, id, deg[N], res[N];
vector<int> g[N], st;
char a[10], b[10];
bool in[N];
queue<int> qu;
vector<pair<int, char> > sol;

inline void addEdge(int u, int v) {
	g[u ^ 1].push_back(v);
	g[v ^ 1].push_back(u);
}

inline int getNode(const string &s) {
	int v, n = s.size();
	sscanf(s.substr(0, n - 1).c_str(), "%d", &v);
	return ((v << 1) + (s[n - 1] == 'w')) << 1;
}

void DFS(int v) {
	low[v] = idx[v] = dfs++;
	in[v] = true;
	st.push_back(v);
	for (int i = 0; i < (int) g[v].size(); ++i) {
		int u = g[v][i];
		if (idx[u] == -1) {
			DFS(u);
			low[v] = min(low[v], low[u]);
		} else if (in[u])
			low[v] = min(low[v], low[u]);
	}
	if (low[v] == idx[v]) {
		src[id] = v;
		int n;
		do {
			n = st.back();
			st.pop_back();
			in[n] = false;
			comp[n] = id;
		} while (n != v);
		++id;
	}
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		int M = n * 4;
		for (int i = 0; i < M; ++i) {
			g[i].clear();
			res[i] = idx[i] = -1;
			deg[i] = 0;
		}
		addEdge(2, 2);
		for (int i = 0; i < n; ++i) {
			int u = (i << 1) << 1, v = ((i << 1) + 1) << 1;
			addEdge(u, v);
			addEdge(u ^ 1, v ^ 1);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%s%s", a, b);
			int u = getNode(a), v = getNode(b);
			addEdge(u, v);
		}
		id = dfs = 0;
		for (int i = 0; i < M; ++i)
			if (idx[i] == -1)
				DFS(i);
		bool can = true;
		for (int i = 0; i < M && can; i += 2)
			can &= comp[i] != comp[i ^ 1];
		if (!can) {
			puts("bad luck");
			continue;
		}
		for (int i = 0; i < id; ++i)
			if (res[i] == -1) {
				res[i] = 1;
				res[comp[src[i] ^ 1]] = 0;
			}
		sol.clear();
		for (int i = 4; i < M; i += 2)
			if (res[comp[i]] == res[comp[2]]) {
				int v = i >> 1;
				if (v & 1)
					sol.push_back(make_pair(v >> 1, 'w'));
				else
					sol.push_back(make_pair(v >> 1, 'h'));
			}
		for (int i = 0; i < (int) sol.size(); ++i)
			printf("%s%d%c", i ? " " : "", sol[i].first, sol[i].second);
		puts("");
	}
	return 0;
}
