#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll reverse(ll N) {
	ll rev = 0;
	while (N != 0) {
		rev *= 10;
		rev += N % 10;
		N /= 10;
	}
	return rev;
}

int main(int argc, char **argv) {
	int T, n, m;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		ll sum = reverse(n) + reverse(m);
		printf("%lld\n", reverse(sum));
	}
	return 0;
}
