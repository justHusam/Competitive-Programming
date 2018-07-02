#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e4;
int g[N], n;

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", g + i);
		int res = -2e9, sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += g[i];
			res = max(res, sum);
			if (sum < 0)
				sum = 0;
		}
		if (res > 0)
			printf("The maximum winning streak is %d.\n", res);
		else
			puts("Losing streak.");
	}
	return 0;
}
