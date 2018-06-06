#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 1, M = 6248170;
bitset<N> bs;
int arr[M], idx;

bool check(int n) {
	if (!bs[n])
		return false;
	int sum = 0, rev = 0, temp = n;
	while (temp) {
		int mod = temp % 10;
		sum += mod;
		rev = rev * 10 + mod;
		temp /= 10;
	}
	if (rev == n)
		return false;
	if (!bs[sum])
		return false;
	rev = 0;
	temp = sum;
	while (temp) {
		rev = rev * 10 + temp % 10;
		temp /= 10;
	}
	return rev != sum; //6248169
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (ll i = 2; i < N; ++i)
		if (!bs[i])
			for (ll j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 2; i < N; ++i)
		if (check(i))
			arr[idx++] = i;
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int x;
		scanf("%d", &x);
		printf("Case %d:\n", k++);
		for (int i = 0; i < idx && arr[i] <= x; ++i)
			printf("%d\n", arr[i]);
	}
	return 0;
}
