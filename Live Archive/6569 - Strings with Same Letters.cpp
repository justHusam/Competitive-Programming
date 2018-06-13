#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char a[1001], b[1001];

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%s%s", a, b) > 0 && a[0] != 'E') {
		int aa[26] = { }, bb[26] = { };
		int n = strlen(a), m = strlen(b);
		for (int i = 0; i < n; ++i)
			++aa[a[i] - 'a'];
		for (int i = 0; i < m; ++i)
			++bb[b[i] - 'a'];
		bool ok = true;
		for (int i = 0; i < 26 && ok; ++i)
			ok &= aa[i] == bb[i];
		printf("Case %d: ", cas++);
		if (ok)
			puts("same");
		else
			puts("different");
	}
	return 0;
}
