#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, p[1000];

bool check() {
	for (int i = 0; i < n; ++i) {
		int last = p[i];
		for (int j = i + 1; j < n; ++j)
			if (p[j] < p[i]) {
				if (p[j] > last)
					return false;
				last = p[j];
			}
	}
	return true;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		int x;
		while (scanf("%d", &x) && x != 0) {
			p[0] = x;
			for (int i = 1; i < n; ++i)
				scanf("%d", &p[i]);
			if (check())
				puts("Yes");
			else
				puts("No");
		}
		puts("");
	}
	return 0;
}
