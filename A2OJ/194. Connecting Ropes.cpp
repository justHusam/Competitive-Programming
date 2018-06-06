#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		priority_queue<int> qu;
		for (int x, a = 0; a < n; ++a) {
			scanf("%d", &x);
			qu.push(x);
		}
		while (qu.size() > 1) {
			int a = qu.top() - 1;
			qu.pop();
			int b = qu.top() - 1;
			qu.pop();
			qu.push(a + b);
		}
		cout << qu.top() << "\n";
	}
	return 0;
}
