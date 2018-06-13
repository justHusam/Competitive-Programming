#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, w, a[50];
	while (scanf("%d%d", &n, &w) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (w < a[i])
				break;
			++res;
			w -= a[i];
		}
		printf("%d\n", res);
	}
	return 0;
}
