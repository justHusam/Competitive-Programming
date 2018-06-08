#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e6 + 9;
char s[N];
vector<int> p;

int main(int argc, char **argv) {
	while (true) {
		int n;
		scanf("%d", &n);
		scanf("%s", s);
		if (n == -1)
			break;
		int k = 0, len = strlen(s);
		if (n == len) {
			putchar('1');
			putchar('\n');
			continue;
		}
		p.clear();
		p.resize(len);
		for (int i = 1; i < len; ++i) {
			while (k > 0 && s[k] != s[i])
				k = p[k - 1];
			if (s[i] == s[k])
				++k;
			p[i] = k;
		}
		if (p[len - 1] > n) {
			putchar('0');
			putchar('\n');
			continue;
		}
		printf("%d\n", (n - p[len - 1]) / (len - p[len - 1]));
	}
	return 0;
}
