#include <bits/stdc++.h>
using namespace std;

class BettingStrategy {
public:

	int finalSum(int initSum, string outcome) {
		int p = 1;
		for (size_t i = 0; i < outcome.length(); ++i) {
			if (outcome[i] == 'W')
				initSum += p;
			else {
				initSum -= p;
				p *= 2;
				if (initSum < p)
					return initSum;
			}
		}
		return initSum;
	}
};
