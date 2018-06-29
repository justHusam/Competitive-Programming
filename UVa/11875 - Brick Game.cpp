#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T, n, a[12];
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Case %d: %d\n", it, a[n / 2]);
	}
	return 0;
}
