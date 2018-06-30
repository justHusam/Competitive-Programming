#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int cum[10001];
bitset<N> bs;
vector<int> p;

inline bool check(int x){
	ll n = 1LL * x * x + x + 41;
	if (n < N)
		return !bs[n];
	for (int i = 0; i < p.size() && 1LL * p[i] * p[i] <= n; ++i)
		if (n % p[i] == 0)
			return false;
	return true;
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 0; i < N; ++i)
		if (!bs[i])
			p.push_back(i);
	for (int i = 0; i <= 10000; ++i){
		if (i != 0)
			cum[i] += cum[i - 1];
		if (check(i))
			++cum[i];
	}
	int l, r;
	while (scanf("%d%d", &l, &r) != EOF){
		int primes = cum[r] - (l ? cum[l - 1] : 0);
		printf("%.2lf\n", 100.0 * primes / (r - l + 1) + 1e-9);
	}
	return 0;
}