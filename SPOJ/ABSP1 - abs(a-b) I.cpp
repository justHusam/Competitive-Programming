#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 9;
int n, v[N];
ll cum[N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		ll sum = 0;
		for (int i = 1; i < n; ++i)
			sum += v[i] - v[0];
		ll res = 0;
		for (int i = 1; i < n; ++i) {
			res += sum;
			sum -= (v[i] - v[i - 1]) * (n - i);
		}
		cout << res << "\n";
	}
	return 0;
}
