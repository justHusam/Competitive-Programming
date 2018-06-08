#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (b == 0)
			printf("Airborne wins.\n");
		else if (b == 1)
			printf("Pagfloyd wins.\n");
	}
	return 0;
}
