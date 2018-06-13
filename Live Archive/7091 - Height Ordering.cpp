#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int cas, a[20];
		scanf("%d", &cas);
		for (int i = 0; i < 20; ++i)
			scanf("%d", &a[i]);
		int need = 0;
		for (int i = 1; i < 20; ++i) {
			int j = i;
			while (j > 0 && a[j] < a[j - 1]) {
				++need;
				swap(a[j], a[j - 1]);
				--j;
			}
		}
		printf("%d %d\n", cas, need);
	}
	return 0;
}
