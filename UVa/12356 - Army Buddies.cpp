#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e5 + 1;
int L[N], R[N];

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0 && n != 0) {
		for (int i = 1; i <= n; ++i)
			L[i] = i - 1, R[i] = i + 1;
		L[1] = -1;
		R[n] = -1;
		while (m-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			int l = L[a], r = R[b];
			if (l == -1 && r == -1) {
				puts("* *");
				continue;
			}
			if (l == -1) {
				L[r] = -1;
				printf("* %d\n", r);
				continue;
			}
			if (r == -1) {
				R[l] = -1;
				printf("%d *\n", l);
				continue;
			}
			L[r] = l;
			R[l] = r;
			printf("%d %d\n", l, r);
		}
		puts("-");
	}
	return 0;
}
