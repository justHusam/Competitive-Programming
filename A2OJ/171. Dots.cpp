#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

map<int, int> hs;

int main(int argc, char **argv) {
	int s = 1;
	hs[1] = 1;
	for (int i = 2;; ++i) {
		s += i;
		if (s > 50005000)
			break;
		hs[s] = i;
	}
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		ll m = hs[n];
		if (m == 0) {
			puts("No");
			continue;
		}
		ll a = m * m;
		a *= 2;
		double s = sqrt(a);
		if (fabs(s / m - sqrt(2)) < 0.0000001)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
