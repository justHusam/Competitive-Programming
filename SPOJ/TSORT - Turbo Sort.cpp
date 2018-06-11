#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N];

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		printf("%d\n", a[i]);
	return 0;
}
