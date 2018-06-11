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
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (b - a == c - b)
			printf("%d\n", c + (c - b));
		else
			printf("%d\n", c * (b / a));
	}
	return 0;
}
