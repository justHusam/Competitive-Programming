#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n > -1) {
		pair<ll, ll> res = make_pair(0, 1);
		while (n-- != 0) {
			ll fem = res.second - 1;
			ll mel = res.first;
			res.first += fem + 1 + mel;
			res.first -= mel;
			res.second -= fem;
			res.second += mel;
		}
		printf("%lld %lld\n", res.first, res.first + res.second);
	}
	return 0;
}
