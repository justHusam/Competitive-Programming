#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int res[1111];

int calc(int x) {
	int res = 0;
	for (int i = 1; i <= x; ++i)
		if (x % i == 0)
			res += i;
	return res;
}

int main(int argc, char **argv) {
	memset(res, -1, sizeof res);
	for (int i = 1; i <= 1000; ++i) {
		int get = calc(i);
		if (get <= 1000)
			res[get] = i;
	}
	int n, k = 1;
	while (scanf("%d", &n) > 0 && n != 0)
		printf("Case %d: %d\n", k++, res[n]);
	return 0;
}
