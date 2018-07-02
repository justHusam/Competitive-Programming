#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	char s[100], res[100];
	while (scanf("%s", s) != 0 && s[0] != '-') {
		if (s[0] == '0' && s[1] == 'x') {
			int x;
			sscanf(s, "%x", &x);
			printf("%d\n", x);
		} else {
			int x = atoi(s), n = 0;
			while (x != 0) {
				if (x % 16 < 10)
					res[n++] = x % 16 + 48;
				else
					res[n++] = x % 16 + 55;
				x /= 16;
			}
			res[n] = '\0';
			reverse(res, res + n);
			printf("0x%s\n", res);
		}
	}
	return 0;
}
