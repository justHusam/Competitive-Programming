#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
bitset<N> bs;
int cum[N], Pow[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

bool check(int n) {
	if ((n & 1) == 0 || bs[n])
		return false;
	int d = 0, nn = n;
	for (; nn; nn /= 10)
		++d;
	for (int i = 1; i < d; ++i) {
		int m = n % 10;
		n /= 10;
		n = m * Pow[d - 1] + n;
		if ((n & 1) == 0 || bs[n])
			return false;
	}
	return true;
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 3; i * i < N; i += 2)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 1; i < N; ++i)
		cum[i] = cum[i - 1] + check(i);
	int a, b;
	while (scanf("%d", &a) > 0 && a != -1) {
		scanf("%d", &b);
		int res = cum[b] - cum[a - 1];
		if (!res)
			puts("No Circular Primes.");
		else if (res == 1)
			puts("1 Circular Prime.");
		else
			printf("%d Circular Primes.\n", res);
	}
	return 0;
}
