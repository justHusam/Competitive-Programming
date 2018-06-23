#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 40000;
map<int, int> hs;
bitset<N> bs;
vector<int> p;

int calc(int n) {
	map<int, int>::iterator it = hs.find(n);
	if (it != hs.end())
		return it->second;
	int res = 1, nn = n;
	for (size_t i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
		int can = 0;
		while (n % p[i] == 0) {
			n /= p[i];
			++can;
		}
		res *= (can + 1);
	}
	if (n != 1)
		res <<= 1;
	return hs[nn] = res;
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
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int l, r;
		scanf("%d%d", &l, &r);
		int res = -1, at;
		for (int i = l; i <= r; ++i) {
			int div = calc(i);
			if (div > res) {
				res = div;
				at = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, at, res);
	}
	return 0;
}
