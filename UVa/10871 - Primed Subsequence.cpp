#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4, M = 1e5 + 1;
int n, a[N], cum[N], odd[N];
vector<int> p;
bitset<M> bs;

inline bool isPrime(int n){
	if (n < M)
		return !bs[n];
	for (int i = 0; i < p.size() && 1LL * p[i] * p[i] <= n; ++i)
		if (n % p[i] == 0)
			return false;
	return true;
}

int calc(int len){
	for (int i = 0; i + len <= n; ++i){
		int o = odd[i + len - 1] - (i ? odd[i - 1] : 0);
		int s = cum[i + len - 1] - (i ? cum[i - 1] : 0);
		if ((o & 1) == 1 && isPrime(s))
			return i;
	}
	return -1;
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < M; ++i)
		if (!bs[i])
			for (int j = i * i; j < M; j += i)
				bs[j] = 1;
	int t;
	scanf("%d", &t);
	while (t-- != 0){
		scanf("%d", &n);
		cum[0] = odd[0] = 0;
		for (int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			if (i != 0){
				cum[i] = cum[i - 1];
				odd[i] = odd[i - 1];
			}
			cum[i] += a[i];
			odd[i] += a[i] & 1;
		}
		int res = -1, str = -1;
		for (int i = 2; i <= n; ++i){
			int pos = calc(i);
			if (pos != -1){
				res = i;
				str = pos;
				break;
			}
		}
		if (res == -1)
			puts("This sequence is anti-primed.");
		else{
			printf("Shortest primed subsequence is length %d:", res);
			for (int i = 0; i < res; ++i)
				printf(" %d", a[i + str]);
			puts("");
		}
	}
	return 0;
}