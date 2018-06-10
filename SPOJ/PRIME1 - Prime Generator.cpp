#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e5 + 1;
bitset<N> bs, with;
vector<int> p;

void sieve(int n) {
	bs.set();
	p.clear();
	bs[0] = bs[1] = 0;
	for (int i = 3; i * i <= n; i += 2)
		if (bs[i])
			for (int j = i * i; j <= n; j += i)
				bs[j] = 0;
	p.push_back(2);
	for (int i = 3; i <= n; i += 2)
		if (bs[i])
			p.push_back(i);
}

int main(int argc, char **argv) {
	int t, f = 0;
	scanf("%d", &t);
	while (t-- != 0) {
		if (f == 1)
			puts("");
		f = 1;
		int s, e;
		scanf("%d%d", &s, &e);
		sieve(sqrt(e) + 1);
		with.set();
		for (size_t i = 0; i < p.size(); ++i) {
			int b = ((s + p[i] - 1) / p[i]) * p[i];
			if (b == p[i])
				b += p[i];
			for (int j = b; j <= e; j += p[i])
				with[j - s] = 0;
		}
		for (int i = 0; i < N && i + s <= e; ++i)
			if (with[i] && i + s != 1)
				printf("%d\n", i + s);
	}
	return 0;
}
