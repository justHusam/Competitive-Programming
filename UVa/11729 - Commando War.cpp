#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

struct state {
	int b, j;
	state() {
	}
	state(int b, int j) :
			b(b), j(j) {
	}
	bool operator<(const state&e) const {
		if (e.j != j)
			return e.j < j;
		return e.b < b;
	}
} v[1000];

int main(int argc, char **argv) {
	int n, tt;
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &v[i].b, &v[i].j);
		sort(v, v + n);
		int mx = 0, in = 0;
		for (int i = 0; i < n; ++i) {
			mx = max(mx, v[i].b + in);
			in += v[i].b;
			mx = max(mx, v[i].j + in);
		}
		printf("Case %d: %d\n", ++tt, mx);
	}
	return 0;
}
