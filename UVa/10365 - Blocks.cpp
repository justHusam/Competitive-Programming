#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int calc(int x, int y) {
	int res = 2e9;
	for (int i = 1; i <= x; ++i)
		if (x % i == 0) {
			int temp = 0;
			temp += (x / i) * y * 2;
			temp += (x / i) * i * 2;
			temp += y * i * 2;
			res = min(res, temp);
		}
	for (int i = 1; i <= y; ++i)
		if (y % i == 0) {
			int temp = 0;
			temp += x * (y / i) * 2;
			temp += x * i * 2;
			temp += (y / i) * i * 2;
			res = min(res, temp);
		}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, res = 2e9;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			if (n % i == 0)
				res = min(res, calc(i, n / i));
		printf("%d\n", res);
	}
	return 0;
}
