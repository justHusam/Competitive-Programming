#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t, cas = 1, a[3];
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &a[0], &a[1], &a[2]);
		sort(a, a + 3);
		printf("Case %d: ", cas++);
		if ((ll) a[0] + a[1] <= a[2])
			puts("Invalid");
		else if (a[0] == a[1] && a[0] == a[2])
			puts("Equilateral");
		else if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2])
			puts("Isosceles");
		else
			puts("Scalene");
	}
	return 0;
}
