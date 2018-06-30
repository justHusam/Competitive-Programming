#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
const ll oo = 1e12;
bitset<N> bs;
vector<ll> v;

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i*i < N; ++i)
		if (!bs[i])
			for (int j = i*i; j < N; j += i)
				bs[j] = 1;
	for (int i = 0; i < N; ++i)
		if (!bs[i])
			for (ll j = 1LL * i * i; j < oo; j *= i)
				v.push_back(j);
	sort(v.begin(), v.end());
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		int a = lower_bound(v.begin(), v.end(), l) - v.begin();
		int b = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
		printf("%d\n", b - a + 1);
	}
	return 0;
}