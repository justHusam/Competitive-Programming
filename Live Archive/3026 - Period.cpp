#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
char s[N];
int n, F[N];

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) && n != 0) {
		scanf("%s", s);
		for (int i = 1, k = 0; i < n; ++i) {
			while (k != 0 && s[i] != s[k])
				k = F[k - 1];
			if (s[i] == s[k])
				++k;
			F[i] = k;
		}
		printf("Test case #%d\n", cas++);
		for (int i = 0; i < n; ++i) {
			int l = i + 1;
			if (l % (l - F[l - 1]) == 0 && l / (l - F[l - 1]) > 1)
				printf("%d %d\n", l, l / (l - F[l - 1]));
		}
		puts("");
	}
	return 0;
}
