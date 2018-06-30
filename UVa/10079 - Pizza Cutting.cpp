#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	ll n;
	while (scanf("%lld", &n) > 0 && n >= 0) {
		printf("%lld\n", (n * n + n + 2) >> 1);
	}
	return 0;
}