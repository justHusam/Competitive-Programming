#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string s;
	double f = 0, c = 0;
	while (getline(cin, s)) {
		int x;
		scanf("%d\n", &x);
		f += x;
		c++;
	}
	printf("%.1lf\n", f / c);
	return 0;
}
