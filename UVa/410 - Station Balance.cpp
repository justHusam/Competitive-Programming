#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, a[10];
vector<int> sol[5];

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &n, &m) > 0) {
		double all = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &a[i]);
			all += a[i];
		}
		all /= n;
		priority_queue<pair<double, int> > qu;
		for (int i = 0; i < n; ++i) {
			qu.push(make_pair(all, i));
			sol[i].clear();
		}
		sort(a, a + m);
		reverse(a, a + m);
		for (int i = 0; i < m; ++i) {
			pair<double, int> e = qu.top();
			qu.pop();
			e.first -= a[i];
			sol[e.second].push_back(a[i]);
			if (sol[e.second].size() < 2)
				qu.push(e);
		}
		double res = 0;
		printf("Set #%d\n", cas++);
		for (int i = 0; i < n; ++i) {
			printf("%2d:", i);
			int at = 0;
			for (size_t j = 0; j < sol[i].size(); ++j) {
				printf(" %d", sol[i][j]);
				at += sol[i][j];
			}
			res += fabs(all - at);
			puts("");
		}
		printf("IMBALANCE = %.5lf\n\n", res);
	}
	return 0;
}
