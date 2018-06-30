#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

char s[1001];

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0 && strcmp(s, "0")) {
		int res = 0;
		for (int i = strlen(s) - 1; i >= 0; --i)
			res = (res * 10 + (s[i] - '0')) % 11;
		if (res == 0)
			printf("%s is a multiple of 11.\n", s);
		else
			printf("%s is not a multiple of 11.\n", s);
	}
	return 0;
}