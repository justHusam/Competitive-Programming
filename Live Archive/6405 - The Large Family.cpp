#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int g;
	while (scanf("%d", &g) && g) {
		double a = 0, b = 0, c = g;
		for (double i = 0; i <= g; i += 0.5) {
			double need = i * 5 + (i + 0.5) * 2;
			if (need <= g) {
				double rem = g - need;
				if (rem < c) {
					c = rem;
					a = i + 0.5;
					b = i;
				}
			}
			need = i * 7;
			if (need <= g) {
				double rem = g - need;
				if (rem < c) {
					c = rem;
					a = b = i;
				}
			}
			if (i == 0)
				continue;
			need = i * 5 + (i - 0.5) * 2;
			if (need <= g) {
				double rem = g - need;
				if (rem < c) {
					c = rem;
					a = i - 0.5;
					b = i;
				}
			}
		}
		printf("%.1lf %.1lf %.1lf %.1lf\n", c, a, a, b);
	}
	return 0;
}
