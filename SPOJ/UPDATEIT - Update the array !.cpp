#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 1;
int n, m, q, s[N], sol[N];

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		while (m-- != 0) {
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			s[l] += v;
			s[r + 1] -= v;
		}
		int add = 0;
		for (int i = 0; i < n; ++i) {
			add += s[i];
			sol[i] = add;
			s[i] = 0;
		}
		scanf("%d", &q);
		while (q-- != 0) {
			int p;
			scanf("%d", &p);
			printf("%d\n", sol[p]);
		}
	}
	return 0;
}
