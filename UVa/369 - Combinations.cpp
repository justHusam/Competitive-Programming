#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
int n, m, freqA[N], freqB[N];
bool isPrime[N];
vector<int> p, pf[N];

void calc(int n, vector<int> &v) {
	for (size_t i = 0; i < p.size() && p[i] * p[i] <= n; ++i)
		while (n % p[i] == 0) {
			v.push_back(p[i]);
			n /= p[i];
		}
	if (n != 1)
		v.push_back(n);
}

inline void insert(int n, int *freq) {
	for (int i = 1; i <= n; ++i)
		for (size_t j = 0; j < pf[i].size(); ++j)
			++freq[pf[i][j]];
}

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; ++i)
		if (isPrime[i])
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
	for (int i = 0; i < N; ++i)
		if (isPrime[i])
			p.push_back(i);
	for (int i = 1; i < N; ++i)
		calc(i, pf[i]);
	while (scanf("%d%d", &n, &m) > 0 && (n != 0 || m != 0)) {
		for (int i = 0; i < N; ++i)
			freqA[i] = freqB[i] = 0;
		insert(n, freqA);
		insert(m, freqB);
		insert(n - m, freqB);
		ll res = 1;
		for (int i = 0; i < N; ++i) {
			freqA[i] -= freqB[i];
			for (int j = 0; j < freqA[i]; ++j)
				res *= i;
		}
		printf("%d things taken %d at a time is %lld exactly.\n", n, m, res);
	}
	return 0;
}
