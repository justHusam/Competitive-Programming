#include <bits/stdc++.h>
using namespace std;

int n, k, at[26];
char s[505];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%s", &n, &k, &s);
		memset(at, -1, sizeof at);
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int p = s[i] - 'A';
			if (at[p] != -1 && i - k < at[p])
				++res;
			at[p] = i + 1;
		}
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
