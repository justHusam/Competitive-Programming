#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
char s[N];
int cum[N];

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%s", s) > 0) {
		int n = strlen(s);
		for (int i = 1; i <= n; ++i)
			cum[i] = cum[i - 1] + (s[i - 1] == '1');
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", cas++);
		while (q-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (b < a)
				swap(a, b);
			int v = cum[b + 1] - cum[a];
			if (v == 0 || v == b - a + 1)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
