#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, a[N], need;

int main(int argc, char **argv) {
	int T, cas = 1;
	scanf("%d", &T);
	while (T-- != 0) {
		printf("Scenario #%d:\n", cas++);
		scanf("%d%d", &need, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		reverse(a, a + n);
		int res = 0;
		for (int i = 0; i < n && need > 0; ++i) {
			++res;
			need -= a[i];
		}
		if (need > 0)
			puts("impossible");
		else
			printf("%d\n", res);
		puts("");
	}
	return 0;
}
