#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t, k = 1;
	string s = "ACM-ACPC-2013";
	scanf("%d", &t);
	while (t-- != 0) {
		int x, y;
		scanf("%d%d", &x, &y);
		int n = s.length(), i = 0;
		x += y;
		while (x-- != 0) {
			++i;
			if (i == n)
				i = 0;
		}
		printf("Case %d: %c\n", k++, s[i]);
	}
	return 0;
}
