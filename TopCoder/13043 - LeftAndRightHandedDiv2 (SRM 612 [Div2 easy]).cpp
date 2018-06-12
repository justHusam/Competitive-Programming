#include <bits/stdc++.h>
using namespace std;

class LeftAndRightHandedDiv2 {

public:

	int count(string S) {
		int res = 0;
		for (size_t i = 0; i + 1 < S.length(); ++i)
			if (S[i] == 'R' && S[i + 1] == 'L')
				++res;
		return res;
	}
};
