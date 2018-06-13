#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("a", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int a[20];
		for (int i = 0; i < 20; ++i)
			scanf("%d", &a[i]);
		for (int i = 19; i > 0; --i) {
			a[i - 1] += a[i] / 2;
			a[i] &= 1;
		}
		for (int i = 0; i < 20; ++i)
			printf("%s%d", i ? " " : "", a[i]);
		puts("");
	}
	return 0;
}
