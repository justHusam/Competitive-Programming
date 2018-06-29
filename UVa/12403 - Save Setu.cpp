#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	string operation;
	int cur = 0, m;
	cin >> T;
	while (T-- != 0) {
		cin >> operation;
		if (operation == "donate") {
			scanf("%d", &m);
			cur += m;
		} else
			printf("%d\n", cur);
	}
	return 0;
}
