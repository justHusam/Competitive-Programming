#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		int res = 0;
		for (int i = n; i >= 1; --i)
			res += i * i;
		printf("%i\n", res);
	}
	return 0;
}
