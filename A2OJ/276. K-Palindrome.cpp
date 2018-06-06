#include <bits/stdc++.h>
using namespace std;

char s[100001];

int main() {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int k, f[26] = { };
		scanf("%d%s", &k, s);
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			++f[s[i] - 'a'];
		int o = 0;
		for (int i = 0; i < 26; ++i)
			if ((f[i] & 1) == 1)
				++o;
		if (o <= k && k <= n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
