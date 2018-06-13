#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > g;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) && n != 0) {
		g.clear();
		g.resize(n);
		int mx = 0;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			g[i].resize(x);
			for (int j = 0; j < x; ++j) {
				scanf("%d", &g[i][j]);
				mx = max(mx, g[i][j]);
			}
			sort(g[i].begin(), g[i].end());
		}
		++mx;
		int best = 2e9;
		for (int i = 0; i <= mx; ++i) {
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				int k = lower_bound(g[j].begin(), g[j].end(), i) - g[j].begin();
				int a = k;
				int b = g[j].size() - k;
				sum += abs(a - b);
			}
			best = min(best, sum);
		}
		printf("%d\n", best);
	}
	return 0;
}
