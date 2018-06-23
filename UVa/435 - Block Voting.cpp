#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20;
int n, p[N], sol[N];

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		memset(sol, 0, sizeof sol);
		int all = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
			all += p[i];
		}
		int mx = 1 << n;
		for (int mask = 0; mask < mx; ++mask) {
			int sum = 0;
			for (int i = 0; i < n; ++i)
				if (((mask >> i) & 1) == 1)
					sum += p[i];
			if (sum * 2 <= all)
				continue;
			for (int i = 0; i < n; ++i)
				if (((mask >> i) & 1) == 1 && (sum - p[i]) * 2 <= all)
					++sol[i];
		}
		for (int i = 0; i < n; ++i)
			printf("party %d has power index %d\n", i + 1, sol[i]);
		puts("");
	}
	return 0;
}
