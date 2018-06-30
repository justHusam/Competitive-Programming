#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 15;
int n, m, a[N];

inline ll __lcm(ll a, ll b) {
	return (a / __gcd(a, b)) * b;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < m; ++i)
			scanf("%d", &a[i]);
		int res = 0;
		for (int mask = 0; mask < (1 << m); ++mask) {
			ll lcm = 1;
			int ones = 0;
			for (int i = 0; i < m; ++i)
				if (((mask >> i) & 1) == 1) {
					lcm = __lcm(lcm, a[i]);
					++ones;
				}
			if ((ones & 1) == 1)
				res -= n / lcm;
			else
				res += n / lcm;
		}
		printf("%d\n", res);
	}
	return 0;
}
