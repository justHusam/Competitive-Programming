#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
	bool vis[10] = { };
	while (n != 0) {
		if (vis[n % 10])
			return false;
		vis[n % 10] = true;
		n /= 10;
	}
	return true;
}

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		int res = 0;
		for (int i = n; i <= m; i++) {
			if (check(i))
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
