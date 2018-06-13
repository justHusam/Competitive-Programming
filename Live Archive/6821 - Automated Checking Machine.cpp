#include <bits/stdc++.h>
using namespace std;

int a[5], b[5];

int main(int argc, char **argv) {
	while (scanf("%d", &a[0]) > 0) {
		for (int i = 1; i < 5; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < 5; ++i)
			scanf("%d", &b[i]);
		bool ok = true;
		for (int i = 0; i < 5 && ok; ++i)
			ok &= a[i] != b[i];
		if (ok)
			puts("Y");
		else
			puts("N");
	}
	return 0;
}
