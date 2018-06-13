#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500;
int n, m, g[N][N];
vector<pair<int, int> > v;

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		int q;
		scanf("%d", &q);
		while (q--) {
			int a, b;
			scanf("%d%d", &a, &b);
			v.clear();
			for (int i = 0; i < n; ++i) {
				int l = lower_bound(g[i], g[i] + m, a) - g[i];
				if (l == m)
					continue;
				int r = upper_bound(g[i], g[i] + m, b) - g[i];
				if (r == m || g[i][r] > b)
					--r;
				if (l <= r)
					v.push_back(make_pair(l, r));
			}
			int best = 0;
			for (size_t i = 0; i < v.size(); ++i) {
				int l = 1, r = min(v[i].second - v[i].first + 1, int(v.size() - i)), res = 0;
				while (l <= r) {
					int m = (l + r) >> 1;
					if (v[i + m - 1].first <= v[i].first && v[i].first + m - 1 <= v[i + m - 1].second) {
						l = m + 1;
						res = m;
					} else
						r = m - 1;
				}
				best = max(best, res);
			}
			printf("%d\n", best);
		}
		puts("-");
	}
	return 0;
}
