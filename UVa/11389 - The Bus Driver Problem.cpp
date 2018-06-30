#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, d, r, a[N], b[N];

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &d, &r) > 0 && n + d + r > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		reverse(b, b + n);
		int res = 0;
		for (int i = 0; i < n; ++i)
			res += max(0, a[i] + b[i] - d) * r;
		printf("%d\n", res);
	}
	return 0;
}
