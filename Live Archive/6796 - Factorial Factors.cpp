#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100001;
vector<int> p[N], v;
int n, freq[N];
bitset<N> bs;

void calc(int n) {
	int at = n;
	for (size_t i = 0; i < v.size() && v[i] * v[i] <= n; ++i)
		while (n % v[i] == 0) {
			p[at].push_back(v[i]);
			n /= v[i];
		}
	if (n != 1)
		p[at].push_back(n);
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 0; i < N; ++i)
		if (!bs[i])
			v.push_back(i);
	for (int i = 2; i < N; ++i)
		calc(i);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		memset(freq, 0, sizeof freq);
		for (int i = 2; i <= n; ++i)
			for (size_t j = 0; j < p[i].size(); ++j)
				++freq[p[i][j]];
		int all = 0, d = 0;
		for (int i = 0; i < N; ++i)
			if (freq[i] != 0) {
				all += freq[i];
				++d;
			}
		printf("%d %d\n", d, all);
	}
	return 0;
}
