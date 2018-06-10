#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const double PI = acos(-1);
int N, F;
double v[10001], mx;

inline bool check(double m) {
	int with = 0;
	for (int i = 0; i < N; ++i)
		with += int(v[i] / m);
	return with >= F;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &N, &F);
		++F;
		double mx = 0;
		for (int i = 0, x; i < N; ++i) {
			scanf("%d", &x);
			v[i] = PI * x * x;
			mx = max(mx, v[i]);
		}
		double l = 0, r = mx + 1;
		for (int i = 0; i < 100; ++i) {
			double mid = (l + r) / 2;
			if (check(mid))
				l = mid;
			else
				r = mid;
		}
		printf("%.4lf\n", l);
	}
	return 0;
}
