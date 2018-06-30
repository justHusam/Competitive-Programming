#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int> > mat;

const int N = 15;
int d, n, m, A[N], F[N];

mat mul(mat &a, mat &b) {
	mat res(d, vector<int>(d, 0));
	for (int i = 0; i < d; ++i)
		for (int j = 0; j < d; ++j)
			for (int k = 0; k < d; ++k)
				res[i][j] = (res[i][j] + (ll) a[i][k] * b[k][j]) % m;
	return res;
}

mat Pow(mat &base, int p) {
	mat res(d, vector<int>(d));
	for (int i = 0; i < d; ++i)
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
	while (scanf("%d%d%d", &d, &n, &m) > 0 && d != 0) {
		for (int i = 0; i < d; ++i)
			scanf("%d", &A[i]);
		for (int i = 0; i < d; ++i)
			scanf("%d", &F[i]);
		if (n <= d) {
			printf("%d\n", F[d - 1] % m);
			continue;
		}
		mat a(d, vector<int>(d)), b(d, vector<int>(d));
		for (int i = 0; i < d; ++i)
			a[0][i] = F[i];
		for (int i = 0; i < d; ++i) {
			b[i][d - 1] = A[d - i - 1];
			if (i != 0)
				b[i][i - 1] = 1;
		}
		b = Pow(b, n - d);
		a = mul(a, b);
		printf("%d\n", a[0][d - 1]);
	}
	return 0;
}