#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 105, M = 1000015;
int v[N], y[M], z[M];

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i)
		scanf("%d", v + i);
	int idx = 0, jdx = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k) {
				y[idx++] = v[i] * v[j] + v[k];
				if (v[i] != 0)
					z[jdx++] = v[i] * (v[j] + v[k]);
			}
	sort(z, z + jdx);
	int ans = 0;
	for (int i = 0; i < idx; ++i)
		ans += upper_bound(z, z + jdx, y[i]) - lower_bound(z, z + jdx, y[i]);
	printf("%d\n", ans);
	return 0;
}
