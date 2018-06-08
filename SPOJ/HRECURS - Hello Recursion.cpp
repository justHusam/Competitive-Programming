#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, x, res = 0;
		scanf("%d", &n);
		while (n-- != 0) {
			scanf("%d", &x);
			res += x;
		}
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
