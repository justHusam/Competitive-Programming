#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		char s[11];
		scanf("%s", s);
		int n = strlen(s);
		sort(s, s + n);
		do
			puts(s);
		while (next_permutation(s, s + n));
		puts("");
	}
	return 0;
}