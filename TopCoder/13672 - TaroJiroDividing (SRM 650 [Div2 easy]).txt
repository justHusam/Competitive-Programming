#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class TaroJiroDividing {

public:
	int getNumber(int A, int B) {
		vector<int> x, y;
		while (true) {
			x.push_back(A);
			if ((A & 1) == 1)
				break;
			A >>= 1;
		}
		while (true) {
			y.push_back(B);
			if ((B & 1) == 1)
				break;
			B >>= 1;
		}
		sort(x.begin(), x.end());
		int res = 0;
		for (size_t i = 0; i < y.size(); ++i)
			if (binary_search(x.begin(), x.end(), y[i]))
				++res;
		return res;
	}
};
