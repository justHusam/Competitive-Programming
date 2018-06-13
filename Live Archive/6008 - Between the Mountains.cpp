#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1000;
int n, m, t, v[N], vv[N];

int main(int argc, char **argv) {
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
			scanf("%d", vv + i);
		int res = 2e9;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				res = min(res, abs(v[i] - vv[j]));
		printf("%d\n", res);
	}
	return 0;
}
