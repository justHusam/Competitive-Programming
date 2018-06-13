#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, m, g[N][N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		int need = 0;
		for (int i = 0; i < m; ++i) {
			int lst = n - 1;
			for (int j = n - 1; j >= 0; --j)
				if (g[j][i] == 1) {
					need += lst - j;
					--lst;
				}
		}
		printf("%d\n", need);
	}
	return 0;
}
