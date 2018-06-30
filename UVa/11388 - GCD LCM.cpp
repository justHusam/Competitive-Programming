#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (b % a == 0)
			printf("%d %d\n", a, b);
		else
			puts("-1");
	}
	return 0;
}