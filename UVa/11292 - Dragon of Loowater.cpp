#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		vector<int> v(n), g(m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &g[i]);
		if (m < n) {
			puts("Loowater is doomed!");
			continue;
		}
		sort(v.begin(), v.end());
		sort(g.begin(), g.end());
		int res = 0, with = 0;
		for (int i = 0; i < n; ++i) {
			int p = lower_bound(g.begin(), g.end(), v[i]) - g.begin();
			if (p == (int) g.size())
				break;
			++with;
			res += g[p];
			g.erase(g.begin() + p);
		}
		if (with == n)
			printf("%d\n", res);
		else
			puts("Loowater is doomed!");
	}
	return 0;
}
