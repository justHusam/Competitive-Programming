#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int can = 0;
	sort(a, a + n);
	do
		++can;
	while (can < 6 && next_permutation(a, a + n));
	if (can == 6)
		puts("Yes");
	else
		puts("No");
	return 0;
}
