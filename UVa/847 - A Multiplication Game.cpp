#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> dp[2];
map<ll, int>::iterator it;
ll n;

int calc(ll p, int at) {
	if (p >= n)
		return at ^ 1;
	it = dp[at].find(p);
	if (it != dp[at].end())
		return it->second;
	int res = at ^ 1;
	for (int i = 2; i <= 9; ++i)
		if (calc(p * i, at ^ 1) == at) {
			res = at;
			break;
		}
	return dp[at][p] = res;
}

int main(int argc, char **argv) {
	while (scanf("%lld", &n) != EOF) {
		dp[0].clear();
		dp[1].clear();
		if (calc(1, 0) == 0)
			puts("Stan wins.");
		else
			puts("Ollie wins.");
	}
	return 0;
}