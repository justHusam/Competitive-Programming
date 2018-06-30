#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, col[15], ok;

int calc(int c, int r, int d1, int d2) {
	if (r == ok)
		return 1;
	int res = 0, msk = ok & (~(r | d1 | d2 | col[c]));
	while (msk) {
		int p = msk & -msk;
		msk -= p;
		res += calc(c + 1, r | p, (d1 | p) << 1, (d2 | p) >> 1);
	}
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) && n) {
		memset(col, 0, sizeof col);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				char c;
				scanf(" %c", &c);
				if (c == '*')
					col[j] |= 1 << i;
			}
		ok = (1 << n) - 1;
		printf("Case %d: %d\n", cas++, calc(0, 0, 0, 0));
	}
	return 0;
}
