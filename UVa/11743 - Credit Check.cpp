#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int sum(int n) {
	int res = 0;
	while (n != 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int with = 0;
		char s[10];
		for (int i = 0; i < 4; ++i) {
			scanf("%s", s);
			int n = strlen(s);
			for (int j = 0; j < n; ++j)
				if ((j & 1) == 1)
					with += s[j] - '0';
				else
					with += sum((s[j] - '0') * 2);
		}
		if (with % 10 == 0)
			puts("Valid");
		else
			puts("Invalid");
	}
	return 0;
}
