#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int> > mat;

const int N = 3;
ll n;
int M;

mat mul(mat &a, mat &b) {
	mat res(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k) {
				res[i][j] = (res[i][j] + (ll) a[i][k] * b[k][j]) % M;
			}
	return res;
}

mat Pow(mat &base, ll p) {
	mat res(N, vector<int>(N, 0));
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
	int cas = 1;
	while (scanf("%lld%d", &n, &M) > 0 && M != 0) {
		printf("Case %d: ", cas++);
		if (n <= 1) {
			printf("%lld %d %d\n", n, M, 1 % M);
			continue;
		}
		mat a(N, vector<int>(N, 0)), b(N, vector<int>(N, 0));
		a[0][0] = 1;
		b[0][2] = 2;
		b[0][0] = b[1][2] = b[2][1] = b[2][2] = 1;
		b = Pow(b, n - 1);
		a = mul(a, b);
		printf("%lld %d %d\n", n, M, (a[0][2] + 1) % M);
	}
	return 0;
}
