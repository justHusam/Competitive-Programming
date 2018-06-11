#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 2500;
int a[N], b[N], c[N], d[N], ab[N * N], cd[N * N];

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		int cur = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				ab[cur] = a[i] + b[j];
				cd[cur] = c[i] + d[j];
				++cur;
			}
		sort(ab, ab + cur);
		int res = 0;
		for (int i = 0; i < cur; ++i)
			res += upper_bound(ab, ab + cur, -cd[i]) - lower_bound(ab, ab + cur, -cd[i]);
		printf("%d\n", res);
	}
	return 0;
}
