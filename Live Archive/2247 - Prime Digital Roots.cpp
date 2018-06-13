#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
bool isPrime[N];

int calc(int n) {
	if (isPrime[n])
		return n;
	if (n < 10)
		return -1;
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return calc(sum);
}

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; ++i)
		if (isPrime[i])
			for (int j = i * i; j < N; j += i)
				isPrime[j] = 0;
	int n;
	while (scanf("%d", &n) && n) {
		int res = calc(n);
		printf("%7i", n);
		if (res == -1)
			puts("    none");
		else
			printf("%8i\n", res);
	}
	return 0;
}
