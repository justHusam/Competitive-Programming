#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, a[70];
vector<int> sol[70];
vector<pair<int, int> > v;

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sol[i].clear();
		}
		priority_queue<pair<int, int> > qu;
		for (int i = 0, x; i < m; ++i) {
			scanf("%d", &x);
			qu.push(make_pair(x, i));
		}
		bool can = true;
		for (int i = 0; i < n; ++i) {
			while (!qu.empty() && a[i] != 0) {
				pair<int, int> e = qu.top();
				qu.pop();
				sol[i].push_back(e.second + 1);
				if (--e.first != 0)
					v.push_back(e);
				--a[i];
			}
			can &= a[i] == 0;
			while (!v.empty()) {
				qu.push(v.back());
				v.pop_back();
			}
		}
		printf("%d\n", (int) can);
		if (!can)
			continue;
		for (int i = 0; i < n; ++i, puts(""))
			for (size_t j = 0; j < sol[i].size(); ++j)
				printf("%s%d", j ? " " : "", sol[i][j]);
	}
	return 0;
}
