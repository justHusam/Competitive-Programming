#include <bits/stdc++.h>
using namespace std;

inline double dist(double x, double y, double xx, double yy) {
	double a = x - xx;
	double b = y - yy;
	return sqrt(a * a + b * b);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int s, n, k, m;
		scanf("%d%d%d%d", &s, &n, &k, &m);
		double a = dist(0, 0, n, 0) / s;
		double b = dist(0, 0, m, 0) / k;
		if (a < b)
			cout << -1 << endl;
		else
			printf("%.5lf\n", a - b);
	}
	return 0;
}
