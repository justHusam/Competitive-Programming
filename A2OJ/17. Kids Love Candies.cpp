#include <bits/stdc++.h>
using namespace std;

/*
 *  * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, k;
		scanf("%d%d", &n, &k);
		int res = 0, x;
		while (n-- != 0) {
			scanf("%d", &x);
			res += x / k;
		}
		printf("%d\n", res);
	}
	return 0;
}
