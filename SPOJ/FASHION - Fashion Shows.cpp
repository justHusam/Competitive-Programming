#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		vector<short> a(n), b(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int res = 0;
		for (int i = 0; i < n; ++i)
			res += a[i] * b[i];
		printf("%d\n", res);
	}
	return 0;
}
