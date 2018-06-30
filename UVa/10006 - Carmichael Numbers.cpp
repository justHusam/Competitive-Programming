#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 65000;
bitset<N> bs;

ll Pow(int a, int b, int M) {
	if (b == 0)
		return 1;
	ll res = Pow(a, b >> 1, M);
	res = (res * res) % M;
	if ((b & 1) == 1)
		res = (res * a) % M;
	return res;
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		if (!bs[n]) {
			printf("%d is normal.\n", n);
			continue;
		}
		bool ok = true;
		for (int i = 2; i < n; ++i)
			if (Pow(i, n, n) != i) {
				ok = false;
				break;
			}
		if (ok)
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	}
	return 0;
}