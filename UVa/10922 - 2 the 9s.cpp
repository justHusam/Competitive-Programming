#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

char s[1111];

inline int calc(int x) {
	int res = 0;
	while (x != 0) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0 && s[0] - '0' != 0) {
		int sum = 0, res = 1, n = strlen(s);
		for (int i = 0; i < n; ++i)
			sum += s[i] - '0';
		if (sum % 9 != 0) {
			printf("%s is not a multiple of 9.\n", s);
			continue;
		}
		while (sum != 9) {
			sum = calc(sum);
			++res;
		}
		printf("%s is a multiple of 9 and has 9-degree %d.\n", s, res);
	}
	return 0;
}
