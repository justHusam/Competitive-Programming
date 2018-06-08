#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, v[100];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		int x;
		scanf("%d", &x);
		bool res = false;
		for (int i = 0; i < n && !res; ++i)
			res |= v[i] == x;
		printf("Case %d: %s\n", k++, res ? "YES" : "NO");
	}
	return 0;
}
