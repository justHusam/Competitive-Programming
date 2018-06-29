#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t, all = 0;
	scanf("%d", &t);
	while (t-- != 0) {
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		int can = 1;
		if (d > 7 || ((a > 56 || b > 45 || c > 25) && (a + b + c > 125)))
			can = 0;
		printf("%d\n", can);
		all += can;
	}
	printf("%d\n", all);
	return 0;
}
