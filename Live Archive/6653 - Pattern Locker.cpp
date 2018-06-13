#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 1;
const ll M = 10000000000007;

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, mn, mx;
		scanf("%d%d%d", &n, &mn, &mx);
		n *= n;
		ll res = n;
		ll m = n - mn, at = mn + 1;
		while (mn-- > 1)
			res = (res * --n) % M;
		ll sum = res;
		while (at <= mx) {
			res = (res * m) % M;
			--m;
			++at;
			sum = (sum + res) % M;
		}
		printf("Case %d: %lld\n", cas++, sum);
	}
	return 0;
}
