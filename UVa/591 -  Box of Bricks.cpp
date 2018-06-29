#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, h[55], caseN = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		int sum = 0, res = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &h[i]);
			sum += h[i];
		}
		for (int i = 0; i < n; ++i)
			if (h[i] > sum / n)
				res += h[i] - sum / n;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", caseN, res);
	}
	return 0;
}
