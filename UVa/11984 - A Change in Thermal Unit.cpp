#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	double C, I;
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		scanf("%lf%lf", &C, &I);
		double F = (9.0 / 5) * C + 32 + I;
		C = (F - 32) * (5.0 / 9);
		printf("Case %d: %.2lf\n", it, C);
	}
	return 0;
}
