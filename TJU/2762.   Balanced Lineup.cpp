#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e4 + 1;
int n, q, v[N], seg[N * 4][2];

void build(int p, int l, int r) {
	if (l == r) {
		seg[p][0] = seg[p][1] = v[l];
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, (l + r) / 2 + 1, r);
	seg[p][0] = min(seg[p * 2][0], seg[p * 2 + 1][0]);
	seg[p][1] = max(seg[p * 2][1], seg[p * 2 + 1][1]);
}

int s, e;
int get(int p, int l, int r, int id) {
	if (l > e || r < s)
		return -1;
	if (l >= s && r <= e)
		return seg[p][id];
	int a = get(p * 2, l, (l + r) / 2, id);
	int b = get(p * 2 + 1, (l + r) / 2 + 1, r, id);
	if (a == -1 || b == -1)
		return max(a, b);
	if (id == 0)
		return min(a, b);
	return max(a, b);
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	build(1, 1, n);
	while (q-- != 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		s = a;
		e = b;
		printf("%d\n", get(1, 1, n, 1) - get(1, 1, n, 0));
	}
	return 0;
}
