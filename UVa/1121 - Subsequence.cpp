#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, sum;
	while (scanf("%d%d", &n, &sum) > 0) {
		int res = 2e9, at = 0;
		queue<int> qu;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			qu.push(x);
			at += x;
			while (at >= sum) {
				res = min(res, (int) qu.size());
				at -= qu.front();
				qu.pop();
			}
		}
		if (res == 2e9)
			res = 0;
		printf("%d\n", res);
	}
	return 0;
}
