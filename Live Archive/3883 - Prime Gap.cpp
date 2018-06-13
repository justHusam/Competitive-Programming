#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
bool isPrime[N];
vector<int> p;

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; ++i)
		if (isPrime[i])
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
	for (int i = 0; i < N; ++i)
		if (isPrime[i])
			p.push_back(i);
	int n;
	while (scanf("%d", &n) && n != 0) {
		int k = lower_bound(p.begin(), p.end(), n) - p.begin();
		if (p[k] == n)
			puts("0");
		else
			printf("%d\n", p[k] - p[k - 1]);
	}
	return 0;
}
