#include<bits/stdc++.h>
using namespace std;

class PeacefulLine {

public:
	string makeLine(vector<int> x) {
		int f[26] = { }, mx, N = x.size(), res = 0;
		for (int i = 0; i < N; ++i) {
			++f[x[i]];
			mx = max(mx, f[x[i]]);
		}
		for (int i = 0; i < N && res < mx; i += 2)
			++res;
		if (res == mx)
			return "possible";
		return "impossible";
	}
};
