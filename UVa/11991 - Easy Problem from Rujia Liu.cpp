#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e5;
vector<int> g[N];

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		for (int i = 0; i < n; ++i)
			g[i].clear();
		map<int, int> hs;
		int id = 0;
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			if (hs.find(x) == hs.end())
				hs[x] = id++;
			g[hs[x]].push_back(i);
		}
		while (m-- != 0) {
			int k, v;
			scanf("%d%d", &k, &v);
			v = hs[v];
			--k;
			if (k < (int) g[v].size())
				printf("%d\n", g[v][k]);
			else
				puts("0");
		}
	}
	return 0;
}
