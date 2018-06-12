#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class FallingFactorialPower {
public:
	double compute(int n, int k) {
		double res = 1;
		if (k > 0) {
			for (int i = n - k + 1; i <= n; ++i)
				res *= i;
		} else if (k < 0) {
			for (int i = n + 1; i <= n - k; ++i)
				res /= i;
		}
		return res;
	}
};