#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5;
int n, a[N];
ll seg[N << 2];
char s[10];

void update(int p, int l, int r, int at, int val) {
	if (at < l || at > r)
		return;
	if (l == r) {
		seg[p] = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(p * 2, l, mid, at, val);
	update(p * 2 + 1, mid + 1, r, at, val);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

ll get(int p, int l, int r, int s, int e) {
	if (l > e || r < s)
		return 0;
	if (l >= s && r <= e)
		return seg[p];
	int mid = (l + r) >> 1;
	return get(p * 2, l, mid, s, e) + get(p * 2 + 1, mid + 1, r, s, e);
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		if (cas != 1)
			puts("");
		memset(seg, 0, sizeof seg);
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			update(1, 0, n - 1, i, x);
		}
		printf("Case %d:\n", cas++);
		while (scanf("%s", s) && s[0] != 'E') {
			if (s[0] == 'M') {
				int l, r;
				scanf("%d%d", &l, &r);
				printf("%lld\n", get(1, 0, n - 1, --l, --r));
			} else {
				int x, r;
				scanf("%d%d", &x, &r);
				update(1, 0, n - 1, --x, r);
			}
		}
	}
	return 0;
}
