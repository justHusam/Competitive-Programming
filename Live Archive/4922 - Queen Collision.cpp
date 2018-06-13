#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 1;
int n, g, R[N], C[N], lD[N * 2], rD[N * 2];

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &g);
		for (int i = 0; i <= n; ++i)
			R[i] = C[i] = lD[i] = rD[i] = lD[i + n] = rD[i + n] = 0;
		while (g--) {
			int k, x, y, s, t;
			scanf("%d%d%d%d%d", &k, &x, &y, &s, &t);
			for (int i = 0; i < k; ++i) {
				int r = x + i * s;
				int c = y + i * t;
				++R[r];
				++C[c];
				++lD[r - c + n];
				++rD[r + c];
			}
		}
		long long res = 0;
		for (int i = 1; i <= n; ++i) {
			res += max(0, R[i] - 1);
			res += max(0, C[i] - 1);
			res += max(0, lD[i] - 1);
			res += max(0, rD[i] - 1);
			res += max(0, lD[i + n] - 1);
			res += max(0, rD[i + n] - 1);
		}
		printf("%lld\n", res);
	}
	return 0;
}
