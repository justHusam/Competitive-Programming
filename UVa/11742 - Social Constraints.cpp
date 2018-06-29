#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, a[20], b[20], c[20];

bool check(int *p) {
	int pos[8];
	for (int i = 0; i < n; ++i)
		pos[p[i]] = i;
	for (int i = 0; i < m; ++i) {
		int d = abs(pos[a[i]] - pos[b[i]]);
		if (c[i] > 0 && d > c[i])
			return false;
		if (c[i] < 0 && d < -c[i])
			return false;
	}
	return true;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		int p[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		int res = 0;
		do
			res += check(p);
		while (next_permutation(p, p + n));
		printf("%d\n", res);
	}
	return 0;
}
