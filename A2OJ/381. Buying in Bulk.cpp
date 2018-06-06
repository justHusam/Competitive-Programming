#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, p;
		scanf("%d%d", &n, &p);
		printf("%d %d\n%d\n", n, p, p * n - (n - 1) * 2);
	}
	return 0;
}
