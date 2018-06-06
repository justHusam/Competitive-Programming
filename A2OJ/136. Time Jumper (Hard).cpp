#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bitset<100> vis[10000 * 100 + 1];
int n, y;
vector<int> v;
set<int> res;

void calc(int idx, int sum) {
	if (sum != 0)
		res.insert(sum);
	if (vis[sum][idx] || idx == n)
		return;
	vis[sum][idx] = 1;
	calc(idx + 1, sum);
	calc(idx + 1, sum + v[idx]);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &y, &n);
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		res.clear();
		memset(vis, 0, sizeof vis);
		calc(0, 0);
		set<int>::iterator it;
		for (it = res.begin(); it != res.end(); ++it)
			printf("%d\n", *it + y);
	}
	return 0;
}
