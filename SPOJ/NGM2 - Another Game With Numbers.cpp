#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 15;
int n, k, a[N];

inline ll __lcm(ll a, ll b) {
	return (a / __gcd(a, b)) * b;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &a[i]);
	int res = 0;
	for (int mask = 0; mask < (1 << k); ++mask) {
		ll lcm = 1;
		int ones = 0;
		for (int i = 0; i < k; ++i)
			if (((mask >> i) & 1) == 1) {
				++ones;
				lcm = __lcm(lcm, a[i]);
			}
		if ((ones & 1) == 1)
			res -= n / lcm;
		else
			res += n / lcm;
	}
	printf("%d\n", res);
	return 0;
}
