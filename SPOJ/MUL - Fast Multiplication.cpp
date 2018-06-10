#include <bits/stdc++.h>
using namespace std;
const double PI = 4.0 * atan(1.0);

const complex<double> I(0, 1);

void FFT(double theta, vector<complex<double> > &a) {
	int n = a.size();
	for (int m = n; m >= 2; m >>= 1) {
		int mh = m >> 1;
		for (int i = 0; i < mh; i++) {
			complex<double> w = exp(i * theta * I);
			for (int j = i; j < n; j += m) {
				int k = j + mh;
				complex<double> x = a[j] - a[k];
				a[j] += a[k];
				a[k] = w * x;
			}
		}
		theta *= 2;
	}
	int i = 0;
	for (int j = 1; j < n - 1; j++) {
		for (int k = n >> 1; k > (i ^= k); k >>= 1)
			;
		if (j < i)
			swap(a[i], a[j]);
	}
}
void FFT(vector<complex<double> > &a) {
	int n = ceil(log(a.size()) / log(2) + 1e-9);
	a.resize(1 << n);
	FFT(2 * PI / a.size(), a);
}

void iFFT(vector<complex<double> > &a) {
	FFT(-2 * PI / a.size(), a);
	for (size_t i = 0; i < a.size(); i++)
		a[i] /= a.size();
}

const int N = 1e4 + 10;
char a[N], b[N], c[2 * N];
vector<complex<double> > A, B, C;

void solve() {
	int sa = strlen(a);
	int sb = strlen(b);
	int sc = sa + sb + 1;
	A.clear();
	A.resize(sc);
	B.clear();
	B.resize(sc);
	for (int i = sa - 1, j = 0; i >= 0; i--)
		A[j++] = a[i] - '0';
	for (int i = sb - 1, j = 0; i >= 0; i--)
		B[j++] = b[i] - '0';
	FFT(A);
	FFT(B);
	C.clear();
	C.resize(A.size());
	for (size_t i = 0; i < A.size(); i++)
		C[i] = A[i] * B[i];

	iFFT(C);
	for (size_t i = 0; i < C.size() - 1; i++) {
		int cr = round(C[i].real()) / 10;
		C[i] = fmod(round(C[i].real()), 10);
		C[i + 1] += cr;
	}
	int i = C.size() - 1, j;
	while (i >= 0 && fabs(C[i].real()) < 0.5)
		i--;
	if (i < 0) {
		c[0] = '0', c[1] = 0;
		return;
	}
	for (j = 0; i >= 0; j++, i--)
		c[j] = round(C[i].real()) + '0';
	c[j] = 0;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%s", a, b);
		solve();
		printf("%s\n", c);
	}
	return 0;
}
