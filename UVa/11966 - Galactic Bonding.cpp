#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, p[N];
double d, x[N], y[N];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%lf", &n, &d);
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &x[i], &y[i]);
			p[i] = i;
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				double dist = hypot(x[i] - x[j], y[i] - y[j]);
				if (dist <= d || fabs(dist - d) < 1e-4)
					p[find(i)] = find(j);
			}
		int res = 0;
		for (int i = 0; i < n; ++i)
			if (find(i) == i)
				++res;
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
