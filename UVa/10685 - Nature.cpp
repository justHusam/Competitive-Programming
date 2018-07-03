#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 5000;
int p[N], freq[N];
unordered_map<string, int> hs;

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main(int argc, char **argv) {
	int c, r;
	while (scanf("%d%d", &c, &r) && c) {
		hs.clear();
		for (int i = 0; i < c; ++i) {
			char s[35];
			scanf("%s", s);
			hs[s] = i;
		}
		for (int i = 0; i < c; ++i)
			p[i] = i;
		while (r-- != 0) {
			char a[35], b[35];
			scanf("%s%s", a, b);
			p[find(hs[a])] = find(hs[b]);
		}
		memset(freq, 0, sizeof freq);
		int res = 0;
		for (int i = 0; i < c; ++i) {
			int p = find(i);
			++freq[p];
			res = max(res, freq[p]);
		}
		printf("%d\n", res);
	}
	return 0;
}
