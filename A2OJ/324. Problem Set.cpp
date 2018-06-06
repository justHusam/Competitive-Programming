#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, x, y, mn = 2e9, mx = 0;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		while (n-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			mn = min(mn, u + v + c);
			mx = max(mx, u + v + c);
		}
		vector<int> v(m);
		for (int i = 0; i < m; ++i)
			scanf("%d", &v[i]);
		pair<int, vector<int> > res = make_pair(-1, vector<int>());
		int tar = (1 << m) - 1;
		for (int i = 1; i <= tar; ++i) {
			bitset<10> msk = i;
			if (msk.count() < y)
				continue;
			int r1 = 0, r2 = 0, s = 0;
			vector<int> temp;
			for (int j = 0; j < m; ++j)
				if (msk[j]) {
					r1 += mn >= v[j];
					r2 += mx >= v[j];
					s += v[j];
					temp.push_back(v[j]);
				}
			if (r1 != x || r2 != y)
				continue;
			sort(temp.begin(), temp.end());
			if (s > res.first || (s == res.first && temp < res.second))
				res = make_pair(s, temp);
		}
		printf("Case %d:", k++);
		if (res.first == -1) {
			puts(" No Solution.");
			continue;
		}
		for (size_t i = 0; i < res.second.size(); ++i)
			printf(" %d", res.second[i]);
		puts("");
	}
	return 0;
}
