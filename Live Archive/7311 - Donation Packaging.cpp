#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t, A = 0, B = 0, C = 0;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		A += a;
		B += b;
		C += c;
		int can = min(A, min(B, C));
		if (can < 30)
			puts("NO");
		else {
			printf("%d\n", can);
			A -= can;
			B -= can;
			C -= can;
		}
	}
	return 0;
}
