#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 10001;
int n, a[N], mo[N], D[N];
bitset<N> bs;

inline ll nC4(ll n) {
	return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

int main(int argc, char **argv) {
	fill(mo, mo + N, 1);
	for (int i = 2; i < N; ++i)
		if (!bs[i]) {
			for (int j = i; j < N; j += i) {
				bs[j] = 1;
				mo[j] *= -1;
			}
			for (int j = i * i; j < N; j += i * i)
				mo[j] = 0;
		}
	while (scanf("%d", &n) != EOF) {
		int M = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			M = max(M, a[i]);
		}
		for (int i = 0; i <= M; ++i)
			D[i] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 1; j * j <= a[i]; ++j)
				if (a[i] % j == 0) {
					++D[j];
					if (j * j != a[i])
						++D[a[i] / j];
				}
		ll res = nC4(n);
		for (int i = 2; i <= M; ++i)
			res += mo[i] * nC4(D[i]);
		printf("%lld\n", res);
	}
	return 0;
}
