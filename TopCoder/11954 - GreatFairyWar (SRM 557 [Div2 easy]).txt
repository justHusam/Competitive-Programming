#include <bits/stdc++.h>
using namespace std;

class GreatFairyWar {

public:

	int minHP(vector<int> dps, vector<int> hp) {
		int n = dps.size(), res = 0, temp;
		for (int i = 0; i < n; ++i) {
			int temp = 0;
			for (int j = i; j < n; ++j)
				temp += dps[j];
			res += temp * hp[i];
		}
		return res;
	}
};
