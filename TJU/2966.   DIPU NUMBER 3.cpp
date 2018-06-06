#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	char s[12];
	while (scanf("%s", s) > 0) {
		ll x = atoll(s);
		int n = strlen(s);
		if (s[0] == s[1]) {
			int a = s[0] - '0';
			int b = s[n >> 1] - '0';
			if (n == 8)
				printf("%lld\n", x - 1008990 * (a - b));
			else
				printf("%lld\n", x - 100998990 * (a - b));
		} else {
			int a = s[0] - '0';
			int b = s[1] - '0';
			if (n == 8)
				printf("%lld\n", x + 1008990 * (a - b));
			else
				printf("%lld\n", x + 100998990 * (a - b));
		}
	}
	return 0;
}
