#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

inline int get(int n) {
	int res = 0;
	while (n != 0) {
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	return res;
}

const int N = 1e6;
bool vis[N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int str, tar;
		scanf("%d%d", &str, &tar);
		int lev = 1, res = -1;
		queue<int> qu;
		qu.push(str);
		memset(vis, false, sizeof vis);
		vis[str] = true;
		while (!qu.empty()) {
			int siz = qu.size();
			while (siz-- != 0) {
				const int t = qu.front();
				qu.pop();
				int a = t + 1;
				if (!vis[a]) {
					vis[a] = true;
					qu.push(a);
				}
				int b = get(t);
				if (!vis[b]) {
					vis[b] = true;
					qu.push(b);
				}
				if (a == tar || b == tar) {
					res = lev;
					break;
				}
			}
			if (res != -1)
				break;
			++lev;
		}
		printf("%d\n", res);
	}
	return 0;
}
