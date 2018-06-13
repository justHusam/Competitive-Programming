#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[1000], cum[1001];
pair<ll, int> dp[1000];
vector<int> sol;

inline ll E(ll x) {
	return (x - 100) * (x - 100);
}

pair<int, int> calc(int i) {
	if (i == n)
		return make_pair(0, 0);
	pair<ll, int>&res = dp[i];
	if (res.first != -1)
		return res;
	res = make_pair(E(cum[n] - cum[i]), 1);
	for (int j = i + 1; j < n; ++j) {
		pair<ll, int> temp = calc(j);
		temp.first += E(cum[j] - cum[i]);
		++temp.second;
		if (temp.first < res.first || (temp.first == res.first && temp.second < res.second))
			res = temp;
	}
	return res;
}

void path(int i) {
	if (i == n)
		return;
	pair<ll, int> res = make_pair(E(cum[n] - cum[i]), 1);
	int pos = n;
	for (int j = i + 1; j < n; ++j) {
		pair<ll, int> temp = calc(j);
		temp.first += E(cum[j] - cum[i]);
		++temp.second;
		if (temp.first < res.first || (temp.first == res.first && temp.second < res.second))
			res = temp, pos = j;
	}
	sol.push_back(pos);
	path(pos);
}

int main(int argc, char **argv) {
	bool pL = false;
	while (scanf("%d", &n) && n != 0) {
		if (pL)
			puts("");
		pL = true;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			cum[i + 1] = cum[i] + a[i];
		}
		memset(dp, -1, sizeof dp);
		pair<ll, int> res = calc(0);
		sol.clear();
		sol.push_back(0);
		path(0);
		printf("p=%lld\n", res.first);
		for (size_t i = 0; i < sol.size(); ++i) {
			printf(" %d", sol[i]);
			if ((i + 1) % 30 == 0)
				puts("");
		}
		puts("");
	}
	return 0;
}
