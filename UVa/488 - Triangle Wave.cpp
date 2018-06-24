#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T, n, m;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &m);
		while (m-- != 0) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= i; ++j)
					printf("%d", i);
				puts("");
			}
			for (int i = n - 1; i >= 1; --i) {
				for (int j = 1; j <= i; ++j)
					printf("%d", i);
				puts("");
			}
		}
		if (T != 0)
			puts("");
	}
	return 0;
}
