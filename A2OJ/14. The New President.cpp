#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int> > g(m, vector<int>(n));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				scanf("%d", &g[i][j]);
				--g[i][j];
			}
		vector<int> cnt(n, 0);
		for (int i = 0; i < m; ++i)
			++cnt[g[i][0]];
		int res = -1;
		vector<pair<int, int> > srt(n);
		for (int i = 0; i < n; ++i) {
			srt[i] = make_pair(-cnt[i], i);
			if (cnt[i] > m / 2) {
				res = i + 1;
				break;
			}
		}
		if (res != -1) {
			printf("%d 1\n", res);
			continue;
		}
		sort(srt.begin(), srt.end());
		int f = srt[0].second, cf = 0;
		int s = srt[1].second, cs = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == f) {
					++cf;
					break;
				}
				if (g[i][j] == s) {
					++cs;
					break;
				}
			}
		res = s;
		if (cf > cs)
			res = f;
		printf("%d 2\n", res + 1);
	}
	return 0;
}
