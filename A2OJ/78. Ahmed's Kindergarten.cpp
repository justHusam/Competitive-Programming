#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5;
bool isPrime[N];
vector<int> primes;

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; ++i)
		if (isPrime[i])
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
	for (int i = 3; i < N; ++i)
		if (isPrime[i])
			primes.push_back(i);
	int T, cas = 1;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		int res = 0;
		for (size_t i = 0; i < primes.size() && primes[i] <= n * 2; ++i)
			if (primes[i] <= n)
				res += primes[i] / 2;
			else
				res += n - primes[i] / 2;
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
