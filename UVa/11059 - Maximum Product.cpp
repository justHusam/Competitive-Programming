#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n, v[18], k;

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			ll cur = 1;
			for (int j = i; j < n; ++j) {
				cur *= v[j];
				res = max(res, cur);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++k, res);
	}
	return 0;
}
