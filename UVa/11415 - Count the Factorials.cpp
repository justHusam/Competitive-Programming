#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
bitset<N> bs;
vector<int> p;
int cum[2703664]; // 2703663

int calc(int n) {
	int res = 0;
	for (int i = 0; i < (int) p.size() && p[i] * p[i] <= n; ++i)
		while (n % p[i] == 0) {
			++res;
			n /= p[i];
		}
	if (n != 1)
		++res;
	return res;
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (bs[i] == 0)
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 0; i < N; ++i)
		if (bs[i] == 0)
			p.push_back(i);
	for (int i = 2; i < 2703663; ++i)
		cum[i] = cum[i - 1] + calc(i);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		int l = 1, r = 2703663, res = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (cum[mid] <= n) {
				res = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}
		assert(res != -1);
		printf("%d\n", res + 1);
	}
	return 0;
}
