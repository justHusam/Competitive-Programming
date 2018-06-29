#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, p, q, v[30];
		scanf("%d%d%d", &n, &p, &q);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		sort(v, v + n);
		int res = 0, with = 0;
		for (int i = 0; i < n; ++i) {
			if (res == p || v[i] + with > q)
				break;
			++res;
			with += v[i];
		}
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
