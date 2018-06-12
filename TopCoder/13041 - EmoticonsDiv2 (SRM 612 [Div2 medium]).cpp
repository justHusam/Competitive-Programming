#include <bits/stdc++.h>
using namespace std;

class EmoticonsDiv2 {

public:

	int printSmiles(int smiles) {
		return calc(2, 2, 1, smiles);
	}

	int calc(int m, int n, int p, int s) {
		if (n == s)
			return m;
		if (n > s)
			return 1e9;
		int a = calc(m + 2, n * 2, n, s); // copy and paste
		int b = calc(m + 1, n + p, p, s); // paste
		return min(a, b);
	}
};
