#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int> > v;

int main(int argc, char **argv) {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		v.clear();
		scanf("%d%d", &n, &m);
		for (int i = 1, x; i < n; ++i) {
			scanf("%d", &x);
			v.push_back(make_pair(x, 1));
		}
		for (int i = 1, x; i < m; ++i) {
			scanf("%d", &x);
			v.push_back(make_pair(x, 2));
		}
		sort(v.rbegin(), v.rend());
		int res = 0, x = 1, y = 1;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].second == 1) {
				res += v[i].first * y;
				++x;
			} else {
				res += v[i].first * x;
				++y;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
