#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
char s[N];

bool check(int l, int r) {
	int freq[10] = { }, mx = -1;
	for (int i = l; i <= r; ++i) {
		++freq[s[i] - '0'];
		mx = max(mx, s[i] - '0');
	}
	for (int i = 0; i <= mx; ++i)
		if (freq[i] != 1)
			return false;
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		int res = 0, n = strlen(s);
		for (int i = 0; i < n; ++i)
			for (int j = 1; j <= 10 && i + j <= n; ++j)
				if (check(i, i + j - 1))
					++res;
		printf("%d\n", res);
	}
	return 0;
}
