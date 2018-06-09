#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, k, in[N], par[N];
vector<int> g[N];

int main(int argc, char **argv) {
	scanf("%d%d", &n, &k);
	for (int i = 0, x; i < k; ++i) {
		scanf("%d", &x);
		while (x-- != 0) {
			int j;
			scanf("%d", &j);
			--j;
			g[i].push_back(j);
			++in[j];
		}
	}
	queue<int> qu;
	for (int i = 0; i < n; ++i)
		if (in[i] == 0)
			qu.push(i);
	int boss = 0;
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		par[v] = boss;
		for (size_t i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (--in[u] == 0)
				qu.push(u);
		}
		boss = v + 1;
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", par[i]);
	return 0;
}
