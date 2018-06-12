#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

class KitayutaMart2 {
public:
	int numBought(int K, int T) {
		int res = 0;
		for (int i = 1;; ++i) {
			res += pow(2, i - 1) * K;
			if (res == T)
				return i;
		}
		return -1;
	}
};
