#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class GrabbingTaxi {

public:
	int dist(int x, int y, int xx, int yy) {
		return abs(x - xx) + abs(y - yy);
	}

	int minTime(vector<int> tXs, vector<int> tYs, int gX, int gY, int walkTime, int taxiTime) {
		int res = dist(0, 0, gX, gY) * walkTime;
		int n = tXs.size();
		for (int i = 0; i < n; ++i)
			res = min(res, dist(0, 0, tXs[i], tYs[i]) * walkTime + dist(tXs[i], tYs[i], gX, gY) * taxiTime);
		return res;
	}
};
