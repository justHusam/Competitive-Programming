#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


inline ll calc(ll n) {
	return (n * max(0LL, n - 3)) >> 1;
}

int main(int argc, char **argv) {
	ll N;
	int cas = 1;
	while (scanf("%lld", &N) > 0 && N != 0) {
		int l = 0, r = 1e9, res;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (calc(mid) < N)
				l = mid + 1;
			else {
				res = mid;
				r = mid - 1;
			}
		}
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
