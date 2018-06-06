#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas) {
		printf("Case %d: ", cas);
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int r1 = x + y;
		int r2 = x + z;
		if (r1 >= 6666 && r2 >= 6666) {
			if (y < z)
				puts("dad");
			else
				puts("mom");
			continue;
		}
		if (r1 >= 6666)
			puts("dad");
		else
			puts("mom");
	}
	return 0;
}
