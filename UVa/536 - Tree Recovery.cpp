#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char pre[33], in[33];
int idx, pos[33];

inline void calc(int s, int e) {
	if (s > e)
		return;
	if (s == e) {
		putchar(in[s]);
		++idx;
		return;
	}
	char ch = pre[idx];
	int m = pos[pre[idx++] - 'A'];
	calc(s, m - 1);
	calc(m + 1, e);
	putchar(ch);
}

int main(int argc, char **argv) {
	while (scanf("%s%s", pre, in) > 0) {
		int n = strlen(in);
		for (int i = 0; i < n; ++i)
			pos[in[i] - 'A'] = i;
		idx = 0;
		calc(0, n - 1);
		puts("");
	}
	return 0;
}
