#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		double d, v, u;
		scanf("%lf%lf%lf", &d, &v, &u);
		printf("Case %d: ", k++);
		if (u == 0 || v == 0 || u <= v) {
			puts("can’t determine");
			continue;
		}
		double a = d / u;
		double b = d / sqrt(u * u - v * v);
		printf("%.3lf\n", fabs(a - b));
	}
	return 0;
}
