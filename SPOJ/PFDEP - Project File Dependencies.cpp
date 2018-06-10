#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, in[N];
vector<int> g[N];

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	while (m-- != 0) {
		int u, v, k;
		scanf("%d%d", &u, &k);
		--u;
		while (k-- != 0) {
			scanf("%d", &v);
			--v;
			g[v].push_back(u);
			++in[u];
		}
	}
	priority_queue<int> qu;
	for (int i = 0; i < n; ++i)
		if (in[i] == 0)
			qu.push(-i);
	vector<int> sol;
	while (!qu.empty()) {
		int v = -qu.top();
		qu.pop();
		sol.push_back(v + 1);
		for (size_t i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (--in[u] == 0)
				qu.push(-u);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%s%d", i ? " " : "", sol[i]);
	return 0;
}
