#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, with, type[N], p[N], q[N];

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &with) > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &type[i], &p[i], &q[i]);
			--type[i];
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int need[] = { 2e9, 2e9, 2e9, 2e9, 2e9, 2e9 };
			need[type[i]] = p[i];
			for (int j = 0; j < n; ++j)
				if (q[j] >= q[i])
					need[type[j]] = min(need[type[j]], p[j]);
			ll cost = 0;
			for (int j = 0; j < 6; ++j)
				cost += need[j];
			if (cost <= with)
				res = max(res, q[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}
