#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%lld", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		ll sum = 0, candies;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &candies);
			sum = (sum + candies) % n;
		}
		if (n != 0)
			if (sum == 0)
				printf("YES\n");
			else
				printf("NO\n");
	}
	return 0;
}
