#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool check(char *s, char ch) {
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
		if (tolower(s[i]) == ch)
			return true;
	return false;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas) {
		printf("Case %d:\n", cas);
		int n;
		char f[1111], s[1111];
		scanf("%d%s%s", &n, f, s);
		while (n-- != 0) {
			char x[1111];
			scanf("%s", x);
			char a = tolower(f[0]);
			char b = tolower(s[0]);
			if (a == b && check(x, a))
				puts("YES");
			else if (a != b)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
