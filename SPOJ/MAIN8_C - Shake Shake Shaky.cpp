#include <bits/stdc++.h>
using namespace std;

const int N = 50000;
int n, k, v[N];

bool check(int x) {
	long long res = 0;
	for (int i = 0; i < n && res < k; ++i)
		res += v[i] / x;
	return res >= k;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &k);
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			mx = max(mx, v[i]);
		}
		int l = 1, r = mx + 1, res = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				res = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
