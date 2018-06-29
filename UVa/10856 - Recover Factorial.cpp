#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e6;
int pf[N];

int main(int argc, char **argv) {
	fill(pf, pf + N, 1);
	pf[0] = pf[1] = 0;
	for (int i = 2; i < N; ++i)
		if (pf[i] == 1)
			for (int j = 2; j * i < N; ++j)
				pf[i * j] = pf[i] + pf[j];
	for (int i = 2; i < N; ++i)
		pf[i] += pf[i - 1];
	int n, cas = 1;
	while (scanf("%d", &n) > 0 && n >= 0) {
		printf("Case %d: ", cas++);
		int k = lower_bound(pf, pf + N, n) - pf;
		if (k == N || pf[k] > n)
			puts("Not possible.");
		else
			printf("%d!\n", k);
	}
	return 0;
}
