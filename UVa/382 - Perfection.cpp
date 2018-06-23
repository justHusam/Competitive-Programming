#include <bits/stdc++.h>
using namespace std;

int calc(int N) {
	int sum = 0;
	for (int i = 1; i * i <= N; ++i)
		if (N % i == 0)
			if (i * i == N)
				sum += i;
			else
				sum += i + N / i;
	return sum;
}

int main(int argc, char **argv) {
	int N;
	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &N) > 0 && N != 0) {
		int sum = calc(N) - N;
		if (sum == N)
			printf("%5d  PERFECT\n", N);
		else if (sum < N)
			printf("%5d  DEFICIENT\n", N);
		else
			printf("%5d  ABUNDANT\n", N);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
