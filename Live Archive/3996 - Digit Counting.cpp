#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int cnt[10];

inline void calc(int n) {
	while (n != 0) {
		++cnt[n % 10];
		n /= 10;
	}
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; ++i)
			calc(i);
		printf("%d", cnt[0]);
		for (int i = 1; i < 10; ++i)
			printf(" %d", cnt[i]);
		puts("");
	}
	return 0;
}
