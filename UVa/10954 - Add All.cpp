#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		priority_queue<int> qu;
		while (n-- != 0) {
			int x;
			scanf("%d", &x);
			qu.push(-x);
		}
		int res = 0;
		while (qu.size() > 1) {
			int cur = 0;
			cur += -qu.top();
			qu.pop();
			cur += -qu.top();
			qu.pop();
			res += cur;
			qu.push(-cur);
		}
		printf("%d\n", res);
	}
	return 0;
}
