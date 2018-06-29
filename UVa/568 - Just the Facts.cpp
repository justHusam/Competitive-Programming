#include <bits/stdc++.h>
using namespace std;

int calc(int N) {
	int add = 0, b, res = 1;
	for (int i = 1; i <= N; ++i) {
		int b = i;
		while (b % 2 == 0) {
			b >>= 1;
			++add;
		}
		while (b % 5 == 0) {
			b /= 5;
			--add;
		}
		res = (res * b) % 10;
	}
	for (; add > 0; --add)
		res = (res * 2) % 10;
	return res;
}

int main(int argc, char **argv) {
	int N;
	while (scanf("%d", &N) > 0)
		printf("%5d -> %d\n", N, calc(N));
	return 0;
}
