#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 1;
bitset<N> bs;
int cum[N];

int sum(int n) {
	int res = 0;
	for (; n; n /= 10)
		res += n % 10;
	return res;
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 1; i < N; ++i)
		cum[i] = cum[i - 1] + (bs[i] == 0 && bs[sum(i)] == 0);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", cum[b] - cum[a - 1]);
	}
	return 0;
}
