#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int m, it = 0;
	while (scanf("%i", &m) > 0) {
		int n = 0;
		vector<pair<int, int> > e;
		while (m-- != 0) {
			int x, y;
			scanf("%d%d", &x, &y);
			e.push_back(make_pair(x, y));
			n = max(n, max(x + 1, y + 1));
		}
		vector<vector<int> > g(n, vector<int>(n, 0));
		vector<vector<bool> > p(n, vector<bool>(n, 0));
		for (size_t i = 0; i < e.size(); ++i) {
			int x = e[i].first, y = e[i].second;
			p[x][y] = g[x][y] = 1;
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					g[i][j] += g[i][k] * g[k][j];
					p[i][j] = p[i][j] | (p[i][k] & p[k][j]);
				}
		vector<int> v;
		for (int i = 0; i < n; ++i)
			if (p[i][i])
				v.push_back(i);
		for (size_t k = 0; k < v.size(); ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					int d = v[k];
					if (p[i][d] && p[d][j])
						g[i][j] = -1;
				}
		printf("matrix for city %d\n", it++);
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < n; ++j)
				printf("%s%d", j ? " " : "", g[i][j]);
	}
	return 0;
}
