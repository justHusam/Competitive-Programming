#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
int n, a[N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			a[i] += a[i - 1];
		}
		map<int, ll> hs;
		for (int i = 0; i <= n; ++i)
			++hs[a[i]];
		ll res = 0;
		map<int, ll>::iterator it;
		for (it = hs.begin(); it != hs.end(); ++it)
			res += (it->second * (it->second - 1)) / 2;
		printf("%lld\n", res);
	}
	return 0;
}
