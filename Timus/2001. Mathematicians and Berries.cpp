#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int a[3], b[3];
	for (int i = 0; i < 3; ++i)
		scanf("%d%d", &a[i], &b[i]);
	printf("%d %d\n", a[0] - a[2], b[0] - b[1]);
	return 0;
}
