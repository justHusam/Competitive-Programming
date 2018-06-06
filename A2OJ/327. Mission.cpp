#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char g[100][1234], v[100][1234];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, k, id = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			scanf("%s%s", v[i], g[i]);
		map<string, int> hs;
		printf("Case %d:\n", cas++);
		for (int i = 0; i < n; ++i) {
			if (id == k)
				break;
			if (hs[g[i]] == m)
				continue;
			++hs[g[i]];
			puts(v[i]);
			++id;
		}
		puts("");
	}
	return 0;
}
