#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[50001];

int check(int l, int r, int len) {
	if (l + len > r - len + 1)
		return -1;
	bool ok = true;
	for (int i = l, j = r - len + 1; len-- && ok; ++i, ++j)
		ok &= s[i] == s[j];
	if (ok)
		return 1;
	return 0;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		int n = strlen(s), l = 0, r = n - 1, res = 0, len = 1;
		while (l <= r) {
			int can = check(l, r, len);
			if (can == -1) {
				++res;
				break;
			}
			if (can == 1) {
				l += len;
				r -= len;
				res += 2;
				len = 0;
			}
			++len;
		}
		printf("Case #%d: %d\n", cas++, res);
	}
	return 0;
}
