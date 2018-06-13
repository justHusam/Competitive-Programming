#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, m, at[3], pos[10];
	bool no[10] = { };
	while (scanf("%d%d", &m, &n) && (n != 0 || m != 0)) {
		memset(no, false, sizeof no);
		memset(pos, 0, sizeof pos);
		for (int i = 0; i < 3; ++i)
			scanf("%d", &at[i]);
		int T = 0, a, b, q;
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			if (i != 0)
				T = (T + 1) % m;
			if (no[T]) {
				--i;
				no[T] = false;
				continue;
			}
			scanf("%d%d", &a, &b);
			pos[T] += a + b;
			for (int j = 0; j < 3; ++j)
				if (at[j] == pos[T]) {
					no[T] = true;
					break;
				}
		}
		printf("%d\n", T + 1);
	}
	return 0;
}
