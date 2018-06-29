#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct state {
	int d, m, y;
	char s[16];
	inline bool operator<(const state&e) const {
		if (e.y != y)
			return e.y < y;
		if (e.m != m)
			return e.m < m;
		return e.d < d;
	}
} a[100];

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s%d%d%d", a[i].s, &a[i].d, &a[i].m, &a[i].y);
	sort(a, a + n);
	printf("%s\n%s\n", a[0].s, a[n - 1].s);
	return 0;
}
