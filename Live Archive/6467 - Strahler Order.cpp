#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, m, in[N], mx[N], res[N];
vector<int> g[N];
map<int, int> freq[N];

int main(int argc, char **argv) {
	int t, cas;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &cas, &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			in[i] = mx[i] = 0;
			freq[i].clear();
		}
		while (m-- != 0) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			g[u].push_back(v);
			++in[v];
		}
		queue<int> qu;
		for (int i = 0; i < n; ++i)
			if (in[i] == 0) {
				qu.push(i);
				mx[i] = res[i] = 1;
			}
		while (!qu.empty()) {
			int v = qu.front();
			qu.pop();
			for (size_t i = 0; i < g[v].size(); ++i) {
				int u = g[v][i];
				--in[u];
				mx[u] = max(mx[u], res[v]);
				++freq[u][res[v]];
				if (in[u] == 0) {
					if (freq[u][mx[u]] > 1)
						res[u] = mx[u] + 1;
					else
						res[u] = mx[u];
					qu.push(u);
				}
			}
		}
		printf("%d %d\n", cas, res[n - 1]);
	}
	return 0;
}
