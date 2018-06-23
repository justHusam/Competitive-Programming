#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int x, y, z;
	state(int x, int y, int z) :
			x(x), y(y), z(z) {
	}
};

int n, dp[200];
vector<state> v;

int calc(int lst) {
	int &res = dp[lst];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 1; i < n; ++i)
		if (v[i].x < v[lst].x && v[i].y < v[lst].y)
			res = max(res, calc(i) + v[i].z);
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		v.clear();
		v.push_back(state(2e9, 2e9, 2e9));
		for (int i = 0; i < n; ++i) {
			int a[3];
			scanf("%d%d%d", &a[0], &a[1], &a[2]);
			sort(a, a + 3);
			do
				v.push_back(state(a[0], a[1], a[2]));
			while (next_permutation(a, a + 3));
		}
		n = v.size();
		memset(dp, -1, sizeof dp);
		printf("Case %d: maximum height = %d\n", cas++, calc(0));
	}
	return 0;
}
