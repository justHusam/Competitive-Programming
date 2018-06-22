#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, k;
	while (scanf("%d%d", &n, &k) > 0 && n != 0) {
		vector<int> take(n, 0), sol;
		int cur = 1, toAdd = 1;
		queue<int> qu;
		for (int i = 0; i < n; ++i)
			qu.push(i);
		while (!qu.empty()) {
			int st = qu.front();
			qu.pop();
			int can = min(cur, 40 - take[st]);
			take[st] += can;
			if (take[st] != 40)
				qu.push(st);
			else
				sol.push_back(st + 1);
			if (cur != can)
				cur -= can;
			else {
				cur = ++toAdd;
				if (cur > k)
					cur = toAdd = 1;
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%3d", sol[i]);
		puts("");
	}
	return 0;
}

