#include <bits/stdc++.h>
using namespace std;

const int N = 25;
bool inS[N];
int id, low[N], idx[N];
vector<vector<int> > g;
vector<int> st;
vector<vector<string> > res;
vector<string> nm;

void DFS(int v) {
	inS[v] = true;
	low[v] = idx[v] = id++;
	st.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!idx[u]) {
			DFS(u);
			low[v] = min(low[v], low[u]);
			continue;
		}
		if (inS[u])
			low[v] = min(low[u], low[v]);
	}
	if (low[v] == idx[v]) {
		vector<string> all;
		int n;
		do {
			n = st.back();
			st.pop_back();
			inS[n] = false;
			all.push_back(nm[n]);
		} while (n != v);
		res.push_back(all);
	}
}

int main(int argc, char **argv) {
	int n, m, k = 1;
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		if (k != 1)
			putchar('\n');
		for (int i = 0; i < n; ++i)
			low[i] = idx[i] = 0;
		g.clear();
		g.resize(n);
		nm.clear();
		map<string, int> hs;
		int siz = 0;
		for (int i = 0; i < m; ++i) {
			char x[35], y[34];
			scanf("%s %s", x, y);
			if (hs.find(x) == hs.end())
				hs[x] = siz++, nm.push_back(x);
			if (hs.find(string(y)) == hs.end())
				hs[y] = siz++, nm.push_back(y);
			g[hs[x]].push_back(hs[y]);
		}
		id = 1;
		res.clear();
		memset(inS, false, sizeof inS);
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i);
		printf("Calling circles for data set %d:\n", k++);
		for (size_t i = 0; i < res.size(); ++i) {
			printf("%s", res[i][0].c_str());
			for (size_t j = 1; j < res[i].size(); ++j)
				printf(", %s", res[i][j].c_str());
			putchar('\n');
		}
	}
	return 0;
}
