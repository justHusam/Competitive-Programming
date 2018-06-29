#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
int n, k;
char s[N][N];

int calc(int at) {
	for (int i = 0; i < k; ++i) {
		bool ok = true;
		for (int j = i; j < k && ok; ++j)
			ok &= s[at][j - i] == s[at - 1][j];
		if (ok)
			return k - i;
	}
	return 0;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &k, &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		int res = k;
		for (int i = 1; i < n; ++i)
			res += k - calc(i);
		printf("%d\n", res);
	}
	return 0;
}
