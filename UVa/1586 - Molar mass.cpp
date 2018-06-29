#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[81];
char ch[] = { 'C', 'H', 'O', 'N' };
double p[] = { 12.01, 1.008, 16.00, 14.01 };

inline double calc(char c) {
	for (int i = 0; i < 4; ++i)
		if (c == ch[i])
			return p[i];
	return 0;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		double res = 0;
		int n = strlen(s), at = 0;
		while (at < n) {
			double w = calc(s[at++]);
			int x = 0;
			while (at < n && isdigit(s[at]))
				x = x * 10 + (s[at++] - '0');
			if (x == 0)
				x = 1;
			res += w * x;
		}
		printf("%.3lf\n", res);
	}
	return 0;
}
