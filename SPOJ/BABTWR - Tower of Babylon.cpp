#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

struct block {
	int x, y, z;
	string o;
	block(int x, int y, int z, string o) :
			x(x), y(y), z(z), o(o) {
	}
};

vector<block> v;
int n;
map<pair<int, string>, int> dp;

int calc(int p, string o) {
	if (dp.find(make_pair(p, o)) != dp.end())
		return dp[make_pair(p, o)];
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (v[i].x < v[p].x && v[i].y < v[p].y)
			res = max(res, calc(i, v[i].o) + v[i].z);
	return dp[make_pair(p, o)] = res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		v.clear();
		for (int i = 0; i < n; ++i) {
			vector<int> p(3);
			for (int j = 0; j < 3; ++j)
				scanf("%d", &p[j]);
			string s = "012";
			do {
				int x = s[0] - '0';
				int y = s[1] - '0';
				int z = s[2] - '0';
				v.push_back(block(p[x], p[y], p[z], s));
			} while (next_permutation(s.begin(), s.end()));
		}
		n = v.size();
		v.push_back(block(2e9, 2e9, 2e9, "012"));
		dp.clear();
		printf("%d\n", calc(n, "012"));
	}
	return 0;
}
