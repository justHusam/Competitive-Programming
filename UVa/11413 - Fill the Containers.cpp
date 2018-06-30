#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, m, a[N];

inline bool check(int mx) {
	int at = 0, with = 0, take = 0;
	while (at < n && take <= m) {
		if (with + a[at] > mx) {
			with = 0;
			++take;
		} else
			with += a[at++];
	}
	return at == n;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		int l = 1, r = 1e9, res = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				res = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		assert(res != -1);
		printf("%d\n", res);
	}
	return 0;
}
