#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

vector<int> primes;
int n, k, dp[1121][200][14];
bool isPrime[1200];

int calc(int sum, int at, int c) {
	if (c == k)
		return sum == n;
	if (sum > n || primes[at] + sum > n)
		return 0;
	if (dp[sum][at][c] != -1)
		return dp[sum][at][c];
	return dp[sum][at][c] = calc(sum + primes[at], at + 1, c + 1) + calc(sum, at + 1, c);
}

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < 1200; ++i)
		if (isPrime[i])
			for (int j = i * i; j < 1200; j += i)
				isPrime[j] = false;
	for (int i = 0; i < 1200; ++i)
		if (isPrime[i])
			primes.push_back(i);
	while (scanf("%d%d", &n, &k) > 0 && n + k > 0) {
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, 0));
	}
	return 0;
}
