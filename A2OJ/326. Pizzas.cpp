#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, res = 0, x;
		scanf("%d", &n);
		while (n-- != 0) {
			scanf("%d", &x);
			res += x;
		}
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
