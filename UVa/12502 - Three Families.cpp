#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		double one = (a + b) / 3.0, ex = 0;
		ex += max(0.0, a - one);
		ex += max(0.0, b - one);
		double h = c / ex;
		printf("%.0lf\n", max(0.0, a - one) * h);
	}
	return 0;
}