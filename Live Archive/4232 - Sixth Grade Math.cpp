#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		int n, m;
		scanf("%d%d", &n, &m);
		int gcd = __gcd(n, m);
		printf("%d %d %d\n", it, (n * m) / gcd, gcd);
	}
	return 0;
}
