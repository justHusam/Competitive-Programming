#include<bits/stdc++.h>
using namespace std;

int n, sum;

bool calc(int i, int w) {
	if (i > n)
		return w == sum;
	return calc(i + 1, w + i) || calc(i + 1, w - i);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &sum);
		if (calc(0, 0))
			puts("Possible");
		else
			puts("Impossible");
	}
	return 0;
}
