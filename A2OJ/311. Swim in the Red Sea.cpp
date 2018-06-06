#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, g[11][11];
vector<int> p;

inline int calc() {
	int res = 0;
	for (int i = 0; i < n; ++i)
		res = max(res, g[i][p[i]]);
	return res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		p.clear();
		for (int i = 0; i < n; ++i)
			p.push_back(i);
		int res = 2e9;
		do
			res = min(res, calc());
		while (next_permutation(p.begin(), p.end()));
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
