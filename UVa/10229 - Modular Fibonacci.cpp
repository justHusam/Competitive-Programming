#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > mat;

int M, N = 2;
ll n;

mat mul(const mat &a, const mat &b) {
	mat res(N, vector<ll>(N, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % M;
	return res;
}

mat Pow(mat &base, ll p) {
	mat res(N, vector<ll>(N, 0));
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
	while (scanf("%lld%d", &n, &M) != EOF) {
		M = 1 << M;
		if (n <= 1) {
			printf("%lld\n", n % M);
			continue;
		}
		mat a(N, vector<ll>(N, 1)), b(N, vector<ll>(N, 0));
		a[0][0] = 0;
		b[0][1] = 1;
		a = Pow(a, n - 1);
		a = mul(b, a);
		printf("%lld\n", a[0][1]);
	}
	return 0;
}