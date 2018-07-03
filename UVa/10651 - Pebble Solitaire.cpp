#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 12;
char s[15];
int dp[1 << N];

int calc(bitset<N> msk) {
	int &res = dp[msk.to_ulong()];
	if (res != -1)
		return res;
	res = msk.count();
	for (int i = 0; i < N - 2; ++i) {
		if (msk[i] == 0 && msk[i + 1] == 1 && msk[i + 2] == 1) {
			msk[i] = 1;
			msk[i + 1] = msk[i + 2] = 0;
			res = min(res, calc(msk));
			msk[i] = 0;
			msk[i + 1] = msk[i + 2] = 1;
			continue;
		}
		if (msk[i] == 1 && msk[i + 1] == 1 && msk[i + 2] == 0) {
			msk[i] = msk[i + 1] = 0;
			msk[i + 2] = 1;
			res = min(res, calc(msk));
			msk[i] = msk[i + 1] = 1;
			msk[i + 2] = 0;
		}
	}
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%s", s);
		memset(dp, -1, sizeof dp);
		bitset<N> msk = 0;
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			msk[i] = s[i] == 'o';
		printf("%d\n", calc(msk));
	}
	return 0;
}
