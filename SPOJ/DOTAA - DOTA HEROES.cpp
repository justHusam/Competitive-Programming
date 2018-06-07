#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, d;
		scanf("%d%d%d", &n, &m, &d);
		priority_queue<int> qu;
		while (n--) {
			int x;
			scanf("%d", &x);
			qu.push(x);
		}
		bool res = true;
		while (m-- && res) {
			int temp = qu.top();
			qu.pop();
			int n = temp - d;
			if (n <= 0)
				res = false;
			else
				qu.push(n);
		}
		if (res)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
