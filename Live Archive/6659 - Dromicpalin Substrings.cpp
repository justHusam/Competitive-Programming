#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001;
char s[N];
int cum[N][26];

bool check(int l, int r) {
	if (l == r)
		return true;
	int odd = 0;
	for (int i = 0; i < 26 && odd <= 1; ++i) {
		int v = cum[r + 1][i] - cum[l][i];
		if (v & 1)
			++odd;
	}
	return odd <= 1;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		int n = strlen(s), res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 26; ++j)
				cum[i + 1][j] = cum[i][j];
			++cum[i + 1][s[i] - 'a'];
		}
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				if (check(i, j))
					++res;
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
