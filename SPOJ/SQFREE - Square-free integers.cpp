#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 1;
bitset<N> bs;
int mo[N];

int main(int argc, char **argv) {
	fill(mo, mo + N, 1);
	for (int i = 2; i < N; ++i)
		if (!bs[i]) {
			for (int j = i; j < N; j += i) {
				bs[j] = 1;
				mo[j] *= -1;
			}
			ll p = (ll) i * i;
			for (ll j = p; j < N; j += p)
				mo[j] = 0;
		}
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		ll n, res = 0;
		scanf("%lld", &n);
		for (ll i = 1; i * i <= n; ++i)
			res += mo[i] * (n / (i * i));
		printf("%lld\n", res);
	}
	return 0;
}
