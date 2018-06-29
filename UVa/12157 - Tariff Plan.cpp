#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int calc(int a, int b) {
	int res = 0;
	for (int i = 0; i <= a; i += b)
		++res;
	return res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		int a = 0, b = 0;
		while (n-- != 0) {
			int x;
			scanf("%d", &x);
			a += calc(x, 30) * 10;
			b += calc(x, 60) * 15;
		}
		printf("Case %d: ", k++);
		if (a < b)
			printf("Mile");
		else if (b < a)
			printf("Juice");
		else
			printf("Mile Juice");
		printf(" %d\n", min(a, b));
	}
	return 0;
}
