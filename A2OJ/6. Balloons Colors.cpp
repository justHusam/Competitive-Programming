#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, x, y, v[100];
		scanf("%d%d%d", &n, &x, &y);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		if (v[0] == x && v[n - 1] == y)
			puts("BOTH");
		else if (v[0] == x)
			puts("EASY");
		else if (v[n - 1] == y)
			puts("HARD");
		else
			puts("OKAY");
	}
	return 0;
}
