#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int t, cas;
	scanf("%d", &t);
	while (t-- != 0) {
		char a[88];
		scanf("%d%s", &cas, a);
		printf("%d ", cas);
		int n = strlen(a);
		if (next_permutation(a, a + n))
			puts(a);
		else
			puts("BIGGEST");
	}
	return 0;
}
