#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	while (cin >> x) {
		for (int a = 1; a <= x; a++)
			if (a % 2 != 0)
				cout << a << endl;
	}
	return 0;
}
