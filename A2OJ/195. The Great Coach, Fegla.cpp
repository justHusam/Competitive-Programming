#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		int a = 0, b = 0;
		while (n-- != 0) {
			int x;
			scanf("%d", &x);
			a += x > 1;
			b += x == 1;
		}
		if (a)
			cout << "ambiguous\n";
		else
			cout << "not ambiguous\n";
	}
	return 0;
}
