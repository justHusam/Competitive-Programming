#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
int n, m, st[N], pf[N];

void calc(int at, int sum, int mask, int src) {
	if (at == m) {
		if (sum != 0)
			return;
		for (int i = 0; i < m; ++i)
			printf("%s%d", i ? " " : "", st[i]);
		puts("");
		return;
	}
	for (int i = src; i <= sum; ++i) {
		if ((pf[i] & mask) == 0) {
			st[at] = i;
			calc(at + 1, sum - i, mask | pf[i], i);
		}
	}
}

int main(int argc, char **argv) {
	int idx = 0;
	for (int i = 2; i < N; ++i)
		if (pf[i] == 0) {
			for (int j = i; j < N; j += i)
				pf[j] |= 1 << idx;
			++idx;
		}
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		printf("Case %d:\n", cas++);
		calc(0, n, 0, 1);
	}
	return 0;
}
