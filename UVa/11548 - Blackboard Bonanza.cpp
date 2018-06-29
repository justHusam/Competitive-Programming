#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

char g[70][80];

int calc(int x, int y) {
	if (x == y)
		return -1;
	int n = strlen(g[x]), m = strlen(g[y]), res = 0;
	for (int i = 0; i < n; ++i) {
		int temp = 0;
		for (int j = i, k = 0; j < n && k < m; ++j, ++k)
			temp += g[x][j] == g[y][k];
		res = max(res, temp);
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				res = max(res, calc(i, j));
		printf("%d\n", res);
	}
	return 0;
}
