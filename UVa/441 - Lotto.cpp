#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, v[15];
vector<vector<int> > res;

inline void calc(int i, bitset<13> msk) {
	if (msk.count() == 6) {
		vector<int> g;
		for (int i = 0; i < n; ++i)
			if (msk[i])
				g.push_back(v[i]);
		res.push_back(g);
		return;
	}
	if (i == n)
		return;
	msk[i] = 1;
	calc(i + 1, msk);
	msk[i] = 0;
	calc(i + 1, msk);
}

int main(int argc, char **argv) {
	bool newLine = false;
	while (scanf("%d", &n) > 0 && n != 0) {
		if (newLine)
			puts("");
		newLine = true;
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		res.clear();
		calc(0, 0);
		for (size_t i = 0; i < res.size(); ++i, puts(""))
			for (int j = 0; j < 6; ++j)
				printf("%s%d", j ? " " : "", res[i][j]);
	}
	return 0;
}
