#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) && n) {
		int f = 0, s = 0;
		for (int a = 0; a < n; a++) {
			int x;
			scanf("%d", &x);
			if (x != 0)
				f++;
			else
				s++;
		}
		printf("Mary won %d times and John won %d times\n", s, f);
	}
	return 0;
}
