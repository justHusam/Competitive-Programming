#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p[101];

int main(int argc, char **argv) {
	p[0] = p[1] = p[2] = 1;
	for (int i = 3; i < 101; ++i)
		p[i] = p[i - 2] + p[i - 3];
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", p[n - 1]);
	}
	return 0;
}
