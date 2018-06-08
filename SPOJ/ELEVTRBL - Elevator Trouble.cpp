#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool vis[1000002];

int main(int argc, char **argv) {
	int n, str, tar, u, d;
	scanf("%d%d%d%d%d", &n, &str, &tar, &u, &d);
	queue<int> qu;
	qu.push(str);
	int lev = 1;
	vis[str] = 1;
	if (str == tar) {
		puts("0");
		return 0;
	}
	if (!u && str < tar) {
		puts("use the stairs");
		return 0;
	}
	if (!d && str > tar) {
		puts("use the stairs");
		return 0;
	}
	while (!qu.empty()) {
		int siz = qu.size();
		while (siz-- != 0) {
			int t = qu.front();
			qu.pop();
			int a = t + u;
			if (a <= n && !vis[a]) {
				vis[a] = true;
				qu.push(a);
				if (a == tar) {
					printf("%d\n", lev);
					return 0;
				}
			}
			int b = t - d;
			if (b >= 0 && !vis[b]) {
				vis[b] = true;
				qu.push(b);
				if (b == tar) {
					printf("%d\n", lev);
					return 0;
				}
			}
		}
		++lev;
	}
	puts("use the stairs");
	return 0;
}
