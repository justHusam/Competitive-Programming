#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 120;
int n, m, k, low[N], idx[N], comp[N], dfs, id;
vector<int> g[N], st;
bool in[N];

inline int getNode(int v, int type) {
	--v;
	v <<= 1;
	if (type)
		v += n << 1;
	return v;
}

inline void addEdge(int u, int v) {
	g[u ^ 1].push_back(v);
	g[v ^ 1].push_back(u);
}

void DFS(int v) {
	low[v] = idx[v] = ++dfs;
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
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &n, &m, &k);
		int M = (n + m) << 1;
		for (int i = 0; i < M; ++i) {
			g[i].clear();
			idx[i] = -1;
		}
		for (int i = 0; i < k; ++i) {
			int s1, a1, s2, a2;
			scanf("%d%d%d%d", &s1, &a1, &s2, &a2);
			s1 = getNode(s1, false), a1 = getNode(a1, true);
			s2 = getNode(s2, false), a2 = getNode(a2, true);
			if (a2 < a1)
				s1 ^= 1, s2 ^= 1;
			if (s2 < s1)
				a1 ^= 1, a2 ^= 1;
			if (s1 == s2)
				addEdge(s1, s2);
			else if (a1 == a2)
				addEdge(a1, a2);
			else {
				addEdge(s1, s2);
				addEdge(s1, a1);
				addEdge(a2, s2);
				addEdge(a2, a1);
			}
		}
		dfs = id = 0;
		for (int i = 0; i < M; ++i)
			if (idx[i] == -1)
				DFS(i);
		bool can = true;
		for (int i = 0; i < M && can; i += 2)
			can &= comp[i] != comp[i ^ 1];
		if (can)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
