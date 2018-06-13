#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e3;
int n, k, m;
vector<int> g[N];
bool vis[N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			vis[i] = false;
		}
		while (m-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i = 0; i < n; ++i) {
			sort(g[i].begin(), g[i].end());
			g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
		}
		int res = n;
		while (true) {
			int mn = 2e9, at = -1;
			for (int i = 0; i < n; ++i) {
				if (vis[i])
					continue;
				int has = 0;
				for (size_t j = 0; j < g[i].size(); ++j)
					if (!vis[g[i][j]])
						++has;
				if (has < mn) {
					mn = has;
					at = i;
				}
			}
			if (at == -1 || mn >= k)
				break;
			--res;
			vis[at] = true;
		}
		printf("%d\n", res);
	}
	return 0;
}
