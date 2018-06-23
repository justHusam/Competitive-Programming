#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, m, c, k = 1, a[20];
	while (scanf("%d%d%d", &n, &m, &c) > 0 && n + m + c > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		bool in[20] = { };
		int mx = 0, w = 0;
		bool res = true;
		while (m-- != 0) {
			int x;
			scanf("%d", &x);
			--x;
			if (in[x]) {
				w -= a[x];
				in[x] = false;
			} else {
				w += a[x];
				in[x] = true;
			}
			res &= w <= c;
			mx = max(mx, w);
		}
		printf("Sequence %d\n", k++);
		if (res)
			printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", mx);
		else
			puts("Fuse was blown.");
		puts("");
	}
	return 0;
}
