#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;

const int N = 2;

matrix mul(const matrix &a, const matrix &b) {
	matrix res(N, vector<ll>(N, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				res[i][j] += a[i][k] * b[k][j];
	return res;
}

matrix Pow(matrix &base, int p) {
	matrix res(N, vector<ll>(N, 0));
	for (int i = 0; i < N; ++i)
		res[i][i] = 1;
	while (p != 0) {
		if (p & 1)
			res = mul(res, base);
		base = mul(base, base);
		p >>= 1;
	}
	return res;
}

int main(int argc, char **argv) {
	int p, q, n;
	while (scanf("%d%d%d", &p, &q, &n) == 3) {
		if (n <= 1) {
			if (n == 0)
				p = 2;
			printf("%d\n", p);
			continue;
		}
		matrix a(N, vector<ll>(N)), b(N, vector<ll>(N));
		a[0][0] = 0;
		a[0][1] = -q;
		a[1][0] = 1;
		a[1][1] = p;
		b[0][0] = 2;
		b[0][1] = p;
		a = Pow(a, n - 1);
		a = mul(b, a);
		printf("%lld\n", a[0][1]);
	}
	return 0;
}