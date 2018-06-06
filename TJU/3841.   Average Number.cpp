#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0) {
		ll res = 0, x;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &x);
			res += x;
		}
		printf("%lld\n", res / n);
	}
	return 0;
}
