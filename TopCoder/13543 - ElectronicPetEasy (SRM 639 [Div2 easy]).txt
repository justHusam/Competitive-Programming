#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class ElectronicPetEasy {

public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
		vector<int> x, y;
		int str = st1;
		for (int i = 0; i < t1; ++i) {
			x.push_back(str);
			str += p1;
		}
		str = st2;
		for (int i = 0; i < t2; ++i) {
			y.push_back(str);
			str += p2;
		}
		for (int i = 0; i < t1; ++i)
			if (binary_search(y.begin(), y.end(), x[i]))
				return "Difficult";
		return "Easy";
	}

};
