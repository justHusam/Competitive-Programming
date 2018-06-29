#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int> > sol;
		for (int i = 2; i * i <= n && sol.size() < 2; ++i)
			if (n % i == 0)
				sol.push_back( { i, n / i });
		printf("Case #%d: %d = %d * %d = %d * %d\n", cas++, n, sol[0].first, sol[0].second, sol[1].first, sol[1].second);
	}
	return 0;
}
