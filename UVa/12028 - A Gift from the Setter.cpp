#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5, M = 1000007;
int n, a[N], K, C;
ll nxt[N], prv[N];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d%d", &K, &C, &n, &a[0]);
		for (int i = 1; i < n; ++i)
			a[i] = (1LL * a[i - 1] * K + C) % M;
		sort(a, a + n);
		nxt[0] = prv[n - 1] = 0;
		for (int i = 1; i < n; ++i)
			nxt[i] = nxt[i - 1] + (a[i] - a[i - 1]) * i;
		for (int i = n - 2; i >= 0; --i)
			prv[i] = prv[i + 1] + (a[i + 1] - a[i]) * (n - i - 1);
		ll sum = 0;
		for (int i = 0; i < n; ++i)
			sum += nxt[i] + prv[i];
		sum >>= 1;
		printf("Case %d: %lld\n", cas++, sum);
	}
	return 0;
}
