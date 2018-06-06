#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, x, n;
	scanf("%d", &T);
	while (T-- != 0) {
		int sum = 0;
		scanf("%d", &n);
		for (int a = 1; a <= n; a++) {
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n\n", sum / n);
	}
	return 0;
}
