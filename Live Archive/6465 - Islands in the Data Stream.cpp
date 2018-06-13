#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t, cas, a[15];
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &cas);
		for (int i = 0; i < 15; ++i)
			scanf("%d", &a[i]);
		int res = 0;
		for (int i = 1; i < 14; ++i)
			for (int j = i; j < 14; ++j) {
				int x = a[i - 1], y = a[j + 1];
				bool ok = true;
				for (int k = i; k <= j && ok; ++k)
					ok &= a[k] > x && a[k] > y;
				if (ok)
					++res;
			}
		printf("%d %d\n", cas, res);
	}
	return 0;
}
