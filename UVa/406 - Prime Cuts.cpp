#include <bits/stdc++.h>
using namespace std;

const int N = 101;
bool isPrime[N];
vector<int> primes;

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = false;
	for (int i = 2; i < N; ++i)
		if (isPrime[i])
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
	for (int i = 0; i < N; ++i)
		if (isPrime[i])
			primes.push_back(i);
	int n, m, toPrint;
	while (scanf("%d%d", &n, &m) > 0) {
		int P = 0;
		for (size_t i = 0; i < primes.size() && primes[i] <= n; ++i)
			P++;
		if (P % 2 == 0)
			toPrint = m * 2;
		else
			toPrint = m * 2 - 1;
		printf("%d %d:", n, m);
		if (toPrint <= P) {
			int pos = P / 2 - toPrint / 2;
			for (int i = pos; i < pos + toPrint; i++)
				printf(" %d", primes[i]);
		} else {
			for (int i = 0; i < P; i++)
				printf(" %d", primes[i]);
		}
		printf("\n\n");
	}
	return 0;
}
