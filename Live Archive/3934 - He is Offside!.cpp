#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, m, a[12], b[12];
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + m);
		bool can = true;
		for (int i = 0; i < n && can; ++i) {
			int k = 0;
			for (int j = 0; j < m; ++j)
				if (b[j] <= a[i]) {
					++k;
				} else
					break;
			can &= k >= 2;
		}
		if (can)
			puts("N");
		else
			puts("Y");
	}
	return 0;
}
