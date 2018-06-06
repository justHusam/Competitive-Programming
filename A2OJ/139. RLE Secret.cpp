#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		char s[2010];
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < n;) {
			int c = 1, p = i + 1;
			while (p < n && s[p] == s[i])
				++c, p++;
			printf("%c%d", s[i], c);
			i = p;
		}
		puts("");
	}
	return 0;
}
