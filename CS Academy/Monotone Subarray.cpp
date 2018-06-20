#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, a[N];

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int str = 0, res = 0, type, at = 0;
	while (at < n) {
		while (at < n && a[at] == a[at - 1])
			++at;
		if (at < n && type == -1) {
			if (a[at] >= a[at - 1])
				type = 0;
			else
				type = 1;
		}
		if (at < n && type == 0 && a[at] > a[at - 1])
			continue;
		if (at < n && type == 1 && a[at] < a[at - 1])
			continue;
		res = max(res, at - str);
		str = at++;
		type = -1;
	}
	printf("%d\n", res);
	return 0;
}
