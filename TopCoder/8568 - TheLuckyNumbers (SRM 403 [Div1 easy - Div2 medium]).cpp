#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class TheLuckyNumbers {
public:
	int count(int a, int b) {
		queue<int> qu;
		if (4 <= b)
			qu.push(4);
		if (7 <= b)
			qu.push(7);
		int res = 0;
		while (!qu.empty()) {
			ll v = qu.front();
			qu.pop();
			if (v >= a && v <= b)
				++res;
			if (v * 10 + 4 <= b)
				qu.push(v * 10 + 4);
			if (v * 10 + 7 <= b)
				qu.push(v * 10 + 7);
		}
		return res;
	}
};
