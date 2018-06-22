#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	char s[55];
	while (scanf("%s", s) > 0 && s[0] != '#') {
		if (next_permutation(s, s + strlen(s)))
			puts(s);
		else
			puts("No Successor");
	}
	return 0;
}
