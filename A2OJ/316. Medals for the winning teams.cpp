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
		int r, l;
		scanf("%d%d", &r, &l);
		int res = l / (2 * r * (22 / 7.0));
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
