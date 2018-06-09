#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
int n, h[N], c[N];

inline ll calc(int H) {
	ll res = 0;
	for (int i = 0; i < n; ++i)
		res += abs(H - h[i]) * c[i];
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &h[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &c[i]);
		int l = 0, r = 1e5;
		ll res = 1LL << 60;
		while (l <= r) {
			int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
			ll a = calc(m1), b = calc(m2);
			if (a <= b)
				r = m2 - 1;
			else
				l = m1 + 1;
			res = min(res, min(a, b));
		}
		printf("%lld\n", res);
	}
	return 0;
}
