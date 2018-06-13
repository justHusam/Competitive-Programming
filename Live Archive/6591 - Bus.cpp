#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int k;
		scanf("%d", &k);
		int res = 0;
		while (k-- != 0) {
			res *= 2;
			++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
