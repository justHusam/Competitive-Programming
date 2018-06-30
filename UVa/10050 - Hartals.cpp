#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool vis[3651];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, p;
		scanf("%d%d", &n, &p);
		memset(vis, false, sizeof vis);
		while (p-- != 0) {
			int x;
			scanf("%d", &x);
			for (int i = x; i <= n; i += x)
				vis[i] = true;
		}
		int res = 0;
		for (int i = 1; i <= n; ++i)
			if (vis[i] && i % 7 != 6 && i % 7 != 0)
				++res;
		printf("%d\n", res);
	}
	return 0;
}
