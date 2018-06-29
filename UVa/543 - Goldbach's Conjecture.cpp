#include <bits/stdc++.h>
using namespace std;

bool isPrime(int N) {
	for (int i = 3; i * i <= N; ++i)
		if (N % i == 0)
			return false;
	return true;
}

int main(int argc, char **argv) {
	int N;
	while (scanf("%d", &N) && N != 0) {
		int x = 0, y = 0;
		for (int i = 3, j = N - 3; j >= i; i += 2, j -= 2)
			if (i + j == N && isPrime(i) && isPrime(j)) {
				x = i;
				y = j;
				break;
			}
		if (x != 0 && y != 0)
			printf("%d = %d + %d\n", N, x, y);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
