#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int K = 1e5 + 1;
vector<int> primes, v;
bool in[1200], isPrime[1200];
int n, tar, dp[K][50], vis[K][50], id;

bool check(int x) {
	int cnt[1200] = { };
	vector<int> v;
	for (size_t i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i) {
		if (x % primes[i] == 0)
			v.push_back(primes[i]);
		while (x % primes[i] == 0) {
			++cnt[primes[i]];
			x /= primes[i];
		}
	}
	if (x != 1) {
		v.push_back(x);
		++cnt[x];
	}
	int o = 0, e = 0;
	for (size_t i = 0; i < v.size(); ++i)
		if ((cnt[v[i]] & 1) == 1)
			++o;
		else
			++e;
	return e > o;
}

int calc(int with, int idx) {
	if (with == tar)
		return 1;
	if (idx == n)
		return with == tar;
	if (with > tar)
		return 0;
	if (vis[with][idx] == id)
		return dp[with][idx];
	vis[with][idx] = id;
	if (calc(with, idx + 1))
		return dp[with][idx] = 1;
	if (calc(with + v[idx], idx + 1))
		return dp[with][idx] = 1;
	return dp[with][idx] = 0;
}

int main() {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 1; i <= 1100; ++i)
		if (isPrime[i])
			for (int j = i * i; j <= 1100; j += i)
				isPrime[j] = false;
	for (int i = 0; i <= 1100; ++i)
		if (isPrime[i])
			primes.push_back(i);
	for (int i = 0; i <= 1200; ++i)
		in[i] = check(i);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &tar);
		v.clear();
		while (n-- != 0) {
			int x;
			scanf("%d", &x);
			if (in[x])
				v.push_back(x);
		}
		n = v.size();
		++id;
		if (calc(0, 0) != 0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
