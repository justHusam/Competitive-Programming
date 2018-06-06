#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, a[N], cum[N];

int calcR() {
	cum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i)
		cum[i] = cum[i + 1] + a[i];
	int res = INT_MAX, sum = 0;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1)
			res = min(res, sum);
		else
			res = min(res, sum * 2 + cum[i + 1]);
		sum += a[i];
	}
	return res;
}

int calcL() {
	cum[0] = 0;
	for (int i = 1; i < n; ++i)
		cum[i] = cum[i - 1] + a[i - 1];
	int res = INT_MAX, sum = 0;
	for (int i = n - 1; i >= 0; --i) {
		sum += a[i];
		if (i == 0)
			res = min(res, sum);
		else
			res = min(res, sum * 2 + cum[i - 1]);
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		printf("%d\n", min(calcL(), calcR()));
	}
	return 0;
}
