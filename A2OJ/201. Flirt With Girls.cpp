#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
int n, X[N], Y[N], r;

inline double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &r);
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (dist(x, y) <= r)
				++res;
		}
		cout << res << endl;
	}
	return 0;
}
