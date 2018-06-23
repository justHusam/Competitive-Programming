#include <bits/stdc++.h>
using namespace std;

bool onSeg(const pair<int, int>& p, const pair<int, int> & q, const pair<int, int> & r) {
	return q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) && q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second);
}

int ori(const pair<int, int>& p, const pair<int, int> & q, const pair<int, int> & r) {
	int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
	return (!val) ? 0 : ((val > 0) ? 1 : 2);
}

bool check(const pair<int, int>& p1, const pair<int, int> & q1, const pair<int, int> & p2, const pair<int, int> & q2) {
	int o1 = ori(p1, q1, p2);
	int o2 = ori(p1, q1, q2);
	int o3 = ori(p2, q2, p1);
	int o4 = ori(p2, q2, q1);
	if (o1 != o2 && o3 != o4)
		return true;
	if (!o1 && onSeg(p1, p2, q1))
		return true;
	if (!o2 && onSeg(p1, q2, q1))
		return true;
	if (!o3 && onSeg(p2, p1, q2))
		return true;
	if (!o4 && onSeg(p2, q1, q2))
		return true;
	return false;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		vector<pair<pair<int, int>, pair<int, int>> > all(n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d%d", &all[i].first.first, &all[i].first.second, &all[i].second.first, &all[i].second.second);
		vector<vector<bool> > g(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = g[j][i] = check(all[i].first, all[i].second, all[j].first, all[j].second);
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] = g[i][j] | (g[i][k] & g[k][j]);
		while (true) {
			int u, v;
			scanf("%d %d", &u, &v);
			if (u == 0)
				break;
			--u, --v;
			if (g[u][v])
				puts("CONNECTED");
			else
				puts("NOT CONNECTED");
		}
		if (T != 0)
			putchar('\n');
	}
	return 0;
}
