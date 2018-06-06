#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	char s[12];
	while (t-- != 0) {
		int n = 0;
		for (int i = 0;; ++i) {
			char c = getchar();
			if (c == EOF || c == '\n')
				break;
			s[n++] = c;
		}
		s[n] = '\0';
		sort(s, s + n);
		do {
			for (int i = 0; i < n; ++i)
				putchar(s[i]);
			putchar('\n');
		} while (next_permutation(s, s + n));
		putchar('\n');
	}
	return 0;
}
