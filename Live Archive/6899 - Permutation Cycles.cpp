#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, a[N];
bool vis[N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			--a[i];
			vis[i] = false;
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (vis[i])
				continue;
			++res;
			int at = i;
			while (a[at] != i) {
				at = a[at];
				vis[at] = true;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
