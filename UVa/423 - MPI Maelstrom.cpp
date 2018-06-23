#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;
char s[111];
int cost[102][102], res;

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	memset(cost, 0x3f, sizeof cost);
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j) {
			scanf("%s", s);
			if (s[0] == 'x')
				continue;
			cost[i][j] = cost[j][i] = atoi(s);
		}
	for (int i = 0; i < n; ++i)
		cost[i][i] = 0;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
	for (int i = 0; i < n; ++i)
		if (cost[i][0] < oo)
			res = max(res, cost[i][0]);
	printf("%d\n", res);
	return 0;
}
