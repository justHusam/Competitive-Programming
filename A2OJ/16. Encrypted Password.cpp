#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
char a[N], b[N];
int need[26], cum[N][26];

bool check(int l, int r) {
	for (int j = 0; j < 26; ++j)
		if (cum[r][j] - cum[l][j] != need[j])
			return false;
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%s", a, b);
		memset(need, 0, sizeof need);
		for (int i = 0; b[i]; ++i)
			++need[b[i] - 'a'];
		memset(cum, 0, sizeof cum);
		int n = strlen(a);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 26; ++j)
				cum[i][j] = cum[i - 1][j];
			++cum[i][a[i - 1] - 'a'];
		}
		int len = strlen(b);
		bool can = false;
		for (int i = 0; i + len <= n && !can; ++i)
			can |= check(i, i + len);
		if (can)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
