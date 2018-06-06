#include <bits/stdc++.h>
using namespace std;

int cost[5][5];

int calc(int *p) {
	if (p[3] == 2)
		return 2e9;
	int res = 0;
	for (int i = 1; i < 5; ++i)
		res += cost[p[i - 1]][p[i]];
	return res;
}

int main(int argc, char **argv) {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			scanf("%d", &cost[i][j]);
	int p[] = { 0, 1, 2, 3, 4 }, need = 2e9, arr[5];
	do {
		int res = calc(p);
		if (res < need) {
			need = res;
			for (int i = 0; i < 5; ++i)
				arr[i] = p[i];
		}
	} while (next_permutation(p + 1, p + 4));
	printf("%d\n", need);
	for (int i = 0; i < 5; ++i)
		printf("%s%d", i ? " " : "", arr[i] + 1);
	return 0;
}
