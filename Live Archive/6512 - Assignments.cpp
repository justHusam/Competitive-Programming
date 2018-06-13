#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int a, b, c;
	state() {
	}
	state(int a, int b, int c) :
			a(a), b(b), c(c) {
	}
};

int n, d;
const int N = 1e3 + 9;
state v[N];

inline bool calc(int i) {
	double a = d / (double) v[i].a;
	double r = a * v[i].c;
	return r <= v[i].b || fabs(r - v[i].b) < 0.000001;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].c);
		int res = 0;
		for (int i = 0; i < n; ++i)
			res += calc(i);
		printf("%d\n", res);
	}
	return 0;
}
