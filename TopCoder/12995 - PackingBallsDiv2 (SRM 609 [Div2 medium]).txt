#include <bits/stdc++.h>
using namespace std;

class PackingBallsDiv2 {

public:

	int minPacks(int R, int G, int B) {
		int res = 0;
		vector<int> v;
		v.push_back(R);
		v.push_back(G);
		v.push_back(B);
		for (int i = 0; i < 3; ++i) {
			if (v[i] >= 3) {
				res += v[i] / 3;
				v[i] %= 3;
			}
		}
		while (!(v[0] <= 0 && v[1] <= 0 && v[2] <= 0)) {
			++res;
			--v[0];
			--v[1];
			--v[2];
		}
		return res;
	}
};
