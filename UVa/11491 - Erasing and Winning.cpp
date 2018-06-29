#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, d, nxt[N][10];
char s[N], res[N];

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &d) > 0 && n + d > 0) {
		scanf("%s", s);
		for (int i = 0; i < 10; ++i)
			nxt[n][i] = 2e9;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 10; ++j)
				nxt[i][j] = nxt[i + 1][j];
			nxt[i][s[i] - '0'] = i;
		}
		int idx = 0, sz = n - d;
		for (int i = 0; i < n; ++i)
			for (int j = 9; j >= !idx; --j)
				if (nxt[i][j] - i <= d) {
					d -= nxt[i][j] - i;
					res[idx++] = char(j + '0');
					i = nxt[i][j];
					break;
				}
		res[sz] = '\0';
		puts(res);
	}
	return 0;
}
