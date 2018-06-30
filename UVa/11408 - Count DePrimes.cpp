#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 1;
int cum[N], sum[N];
bitset<N> bs;

int main(int argc, char **argv) {
	for (int i = 2; i < N; ++i)
		if (!bs[i])
			for (int j = i * 2; j < N; j += i) {
				sum[j] += i;
				bs[j] = 1;
			}
	for (int i = 2; i < N; ++i)
		cum[i] = cum[i - 1] + (!bs[i] || !bs[sum[i]]);
	int a, b;
	while (scanf("%d", &a) > 0 && a != 0) {
		scanf("%d", &b);
		printf("%d\n", cum[b] - cum[a - 1]);
	}
	return 0;
}
