#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int A, B;
		scanf("%d%d", &A, &B);
		int g = __gcd(A, B);
		int r = (A / g) * (B / g);
		printf("%d %d\n", g, r);
	}
	return 0;
}
