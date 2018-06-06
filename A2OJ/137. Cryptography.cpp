#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		string p = "";
		while (n-- != 0) {
			char s[25];
			scanf("%s", s);
			int l = strlen(s);
			for (int i = 0; i < l; ++i) {
				if (isupper(s[i])) {
					s[i] = ((s[i] - 'A' + m) % 26 + 'A');
					s[i] = tolower(s[i]);
					continue;
				}
				s[i] = ((s[i] - 'a' + m) % 26 + 'a');
				s[i] = toupper(s[i]);
			}
			printf("%s%s", p.c_str(), s);
			p = " ";
		}
		puts("");
	}
	return 0;
}
