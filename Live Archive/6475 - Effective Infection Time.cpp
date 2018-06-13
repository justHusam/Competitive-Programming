#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	int a, c;
	char bb[6], dd[6];
	while (t-- != 0) {
		scanf("%d%s%d%s", &a, bb, &c, dd);
		int b = atoi(bb);
		int d = atoi(dd);
		bool str = true;
		double res = 0;
		while (true) {
			if (b == d) {
				if (str) {
					double v = 0.5 / (12 - a + 1);
					res += v * (c - a);
					str = false;
				} else {
					res += 1.0 / 12 * (c - 1);
				}
				break;
			}
			if (str) {
				res += 0.5;
				str = false;
			} else {
				++res;
			}
			++b;
		}
		printf("%.4lf\n", res);
	}
	return 0;
}
