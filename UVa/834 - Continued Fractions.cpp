#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	ll a, b;
	vector<ll> sol;
	while (scanf("%lld%lld", &a, &b) != EOF) {
		sol.clear();
		while (b != 0) {
			sol.push_back(a / b);
			a %= b;
			swap(a, b);
		}
		printf("[");
		for (int i = 0; i < (int) sol.size(); ++i) {
			if (i == 1)
				printf(";");
			else if (i > 1)
				printf(",");
			printf("%lld", sol[i]);
		}
		printf("]\n");
	}
	return 0;
}
