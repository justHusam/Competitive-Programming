#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll n) {
	if ((n & 1) == 1)
		return ((n + 1) / 2) * n;
	return (n / 2) * (n + 1);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		ll n;
		scanf("%lld", &n);
		ll s = 0, e = 2e9, res = 0;
		while (s <= e) {
			ll m = (s + e) / 2;
			if (calc(m) <= n)
				res = max(res, m), s = m + 1;
			else
				e = m - 1;
		}
		printf("%lld\n", res);
	}
	return 0;
}
