#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1, oo = 2e9;
char s[N], res[N];
int nxt[N][10];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int k;
		scanf("%s%d", s, &k);
		int n = strlen(s);
		if (n == k) {
			puts("");
			continue;
		}
		for (int i = 0; i < 10; ++i)
			nxt[n][i] = oo;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 10; ++j)
				nxt[i][j] = nxt[i + 1][j];
			nxt[i][s[i] - '0'] = i;
		}
		int sz = n - k, idx = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 9; j >= 0; --j)
				if (nxt[i][j] - i <= k) {
					res[idx++] = j + '0';
					k -= nxt[i][j] - i;
					i = nxt[i][j];
					break;
				}
		res[sz] = 0;
		puts(res);
	}
	return 0;
}
