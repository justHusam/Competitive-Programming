#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		ll res = 0;
		for (int i = 5; i <= n; i *= 5)
			res += n / i;
		printf("%lld\n", res);
	}
	return 0;
}
