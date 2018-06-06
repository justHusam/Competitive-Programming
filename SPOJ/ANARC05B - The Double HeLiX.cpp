#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e4 + 2;
int c1[N], c2[N], ap[N * 2 + 2];

int main(int argc, char **argv) {
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<int> v1(n + 1);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &v1[i]);
		int m;
		scanf("%d", &m);
		vector<int> v2(m + 1);
		memset(ap, -1, sizeof ap);
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &v2[i]);
			ap[v2[i] + N] = i;
		}
		c1[0] = c2[0] = 0;
		for (int i = 1; i <= n; ++i)
			c1[i] = c1[i - 1] + v1[i];
		for (int i = 1; i <= m; ++i)
			c2[i] = c2[i - 1] + v2[i];
		int l1 = 0, l2 = 0, res = 0;
		for (int i = 1; i <= n; ++i) {
			int p = ap[v1[i] + N];
			if (p == -1)
				continue;
			int s1 = c1[i] - c1[l1];
			int s2 = c2[p] - c2[l2];
			l1 = i;
			l2 = p;
			res += max(s1, s2);
		}
		res += max(c1[n] - c1[l1], c2[m] - c2[l2]);
		printf("%d\n", res);
	}
	return 0;
}
