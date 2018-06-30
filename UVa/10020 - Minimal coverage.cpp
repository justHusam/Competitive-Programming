#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		vector<pair<int, int> > v;
		int x, y, m;
		scanf("%d", &m);
		while (scanf("%d%d", &x, &y) && (x || y))
			v.push_back(make_pair(x, y));
		sort(v.begin(), v.end());
		int pos = 0, n = v.size();
		vector<int> res;
		for (int i = 0; i < n; ++i) {
			int take = -1;
			while (i < n && v[i].first <= pos) {
				if (take == -1 || v[i].second > v[take].second)
					take = i;
				++i;
			}
			if (take == -1) {
				res.clear();
				break;
			}
			i = take;
			pos = v[i].second;
			res.push_back(i);
			if (v[i].second >= m)
				break;
		}
		printf("%d\n", (int) res.size());
		for (size_t i = 0; i < res.size(); ++i)
			printf("%d %d\n", v[res[i]].first, v[res[i]].second);
		if (t != 0)
			puts("");
	}
	return 0;
}
