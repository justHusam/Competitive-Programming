#include <bits/stdc++.h>
using namespace std;

int sum, n, v[12];
set<vector<int> > res;

inline void calc(int i, int s, bitset<12> msk) {
	if (s == sum) {
		vector<int> g;
		for (int i = 0; i < n; ++i)
			if (msk[i])
				g.push_back(v[i]);
		sort(g.rbegin(), g.rend());
		res.insert(g);
		return;
	}
	if (i == n || s > sum)
		return;
	calc(i + 1, s, msk);
	msk[i] = 1;
	calc(i + 1, s + v[i], msk);
	msk[i] = 0;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &sum, &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		res.clear();
		calc(0, 0, 0);
		printf("Sums of %d:\n", sum);
		if (res.empty()) {
			puts("NONE");
			continue;
		}
		set<vector<int> >::reverse_iterator it;
		for (it = res.rbegin(); it != res.rend(); ++it) {
			vector<int> v = *it;
			printf("%d", v[0]);
			for (size_t i = 1; i < v.size(); ++i)
				printf("+%d", v[i]);
			puts("");
		}
	}
	return 0;
}
