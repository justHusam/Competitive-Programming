#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 45000, M = 1e9 + 7;
bitset<N> bs;
vector<int> p;
int n, a[100];
map<int, int> freq;
map<int, int>::iterator it;

void primeFactors(int x) {
	for (int i = 0; i < (int) p.size() && p[i] * p[i] <= x; ++i)
		while (x % p[i] == 0) {
			++freq[p[i]];
			x /= p[i];
		}
	if (x != 1)
		++freq[x];
}

int Pow(int a, int b) {
	if (b == 0)
		return 1;
	ll res = Pow(a, b >> 1);
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
	for (int i = 0; i < N; ++i)
		if (!bs[i])
			p.push_back(i);
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		printf("Case %d: ", cas++);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		freq.clear();
		for (int i = 0; i < n; ++i)
			primeFactors(a[i]);
		ll res = 1;
		for (it = freq.begin(); it != freq.end(); ++it) {
			ll num = ((Pow(it->first, it->second + 1) - 1) % M + M) % M;
			ll den = it->first - 1;
			res = (((res * num) % M) * Pow(den, M - 2)) % M;
		}
		printf("%lld\n", res);
	}
	return 0;
}
