#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 15;
bool isPrime[N];

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; ++i)
		if (isPrime[i])
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		int a, b, res = 0;
		if (n == 4)
			puts("1");
		else {
			for (int i = n - 3, j = 3; i >= j; i -= 2, j += 2) {
				if (i + j == n && isPrime[i] && isPrime[j])
					++res;
				printf("%d\n", res);
			}
		}
	}
	return 0;
}
