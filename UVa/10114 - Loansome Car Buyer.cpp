#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n, m;
	double d, all;
	while (scanf("%d%lf%lf%d", &n, &d, &all, &m) && n >= 0) {
		map<int, double> hs;
		while (m-- != 0) {
			int a;
			double b;
			scanf("%d%lf", &a, &b);
			hs[a] = b;
		}
		int res = 0;
		double x = all + d, y = all, p = hs[0], M = all / n;
		x -= x * p;
		for (int i = 1; x < y; ++i, ++res) {
			if (hs.find(i) != hs.end())
				p = hs[i];
			x -= (x * p);
			y -= M;
		}
		if (res == 1)
			puts("1 month");
		else
			printf("%d months\n", res);
	}
	return 0;
}
