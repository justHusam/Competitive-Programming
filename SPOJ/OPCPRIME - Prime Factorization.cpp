#include<bits/stdc++.h>
#include<map>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e6 + 1;
bool isPrime[N];
vector<int> primes;

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; ++i)
		if (isPrime[i])
			for (ll j = i * i; j < N; j += i)
				isPrime[j] = false;
	for (int i = 0; i < N; ++i)
		if (isPrime[i])
			primes.push_back(i);
	ll n;
	scanf("%lld", &n);
	vector<ll> res;
	for (size_t i = 0; i < primes.size() && (ll) primes[i] * primes[i] <= n; ++i)
		if (n % primes[i] == 0) {
			res.push_back(primes[i]);
			while (n % primes[i] == 0)
				n /= primes[i];
		}
	if (n != 1)
		res.push_back(n);
	for (size_t i = 0; i < res.size(); ++i)
		printf("%lld\n", res[i]);
	return 0;
}
