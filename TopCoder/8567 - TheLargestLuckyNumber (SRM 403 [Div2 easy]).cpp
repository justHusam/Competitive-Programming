#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class TheLargestLuckyNumber {
public:
	int find(int n) {
		queue<int> qu;
		qu.push(4);
		if (7 <= n)
			qu.push(7);
		int mx = 0;
		while (!qu.empty()) {
			int v = qu.front();
			qu.pop();
			mx = max(mx, v);
			if (v * 10 + 4 <= n)
				qu.push(v * 10 + 4);
			if (v * 10 + 7 <= n)
				qu.push(v * 10 + 7);
		}
		return mx;
	}
};
