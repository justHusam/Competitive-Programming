#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n, m, a[101], b[101];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int g = __gcd(a, b), res = 0;
		for (int i = 1; i * i <= g; ++i)
			if (a % i == 0 && b % i == 0) {
				++res;
				if (i * i != g && a % (g / i) == 0 && b % (g / i) == 0)
					++res;
			}
		printf("%d\n", res);
	}
	return 0;
}
