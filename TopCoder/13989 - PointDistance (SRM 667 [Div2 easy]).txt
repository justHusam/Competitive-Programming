#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class PointDistance {
public:
	vector<int> findPoint(int x1, int y1, int x2, int y2) {
		for (int x = -100; x <= 100; ++x)
			for (int y = -100; y <= 100; ++y) {
				if ((x == x1 && y == y1) || (x == x2 && y == y2))
					continue;
				double a = hypot(x - x1, y - y1);
				double b = hypot(x - x2, y - y2);
				if (a > b) {
					vector<int> res;
					res.push_back(x);
					res.push_back(y);
					return res;
				}
			}
		return vector<int>();
	}
};
