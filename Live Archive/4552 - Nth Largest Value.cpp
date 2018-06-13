#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int casN;
		scanf("%d", &casN);
		int a[10];
		for (int i = 0; i < 10; ++i)
			scanf("%d", &a[i]);
		sort(a, a + 10);
		printf("%d %d\n", casN, a[7]);
	}
	return 0;
}
