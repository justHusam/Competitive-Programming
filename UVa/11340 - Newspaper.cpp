#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

char s[10099];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		map<char, double> hs;
		while (n-- != 0) {
			double v;
			char ch;
			scanf(" %c%lf", &ch, &v);
			hs[ch] = v / 100;
		}
		int m;
		scanf("%d", &m);
		double res = 0;
		getchar();
		while (m-- != 0) {
			gets(s);
			stringstream ss(s);
			string t;
			while (ss >> t) {
				for (size_t i = 0; i < t.size(); ++i)
					res += hs[t[i]];
			}
		}
		printf("%.2lf$\n", res);
	}
	return 0;
}
