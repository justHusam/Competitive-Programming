#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T, n, a[52];
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		int res = 0;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < n - i; j++)
				if (a[j] > a[j + 1]) {
					res++;
					swap(a[j], a[j + 1]);
				}
		for (int i = 0; i < n; ++i)
			printf("%d ", a[i]);
		printf("\n");
		printf("Optimal train swapping takes %d swaps.\n", res);
	}
	return 0;
}
