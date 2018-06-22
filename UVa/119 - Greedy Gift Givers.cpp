#include <bits/stdc++.h>
using namespace std;

string s[15];
short sol[15], n;

void calc(string name, short money) {
	for (int i = 0; i < n; i++)
		if (name == s[i]) {
			sol[i] += money;
			break;
		}
}

int main(int argc, char **argv) {
	bool newLine = false;
	while (cin >> n) {
		if (newLine)
			printf("\n");
		for (int i = 0; i < n; ++i)
			sol[i] = 0;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		string name, nameTo;
		int m, to;
		for (short i = 1; i <= n; ++i) {
			cin >> name >> m >> to;
			if (to != 0)
				calc(name, -((m / to) * to));
			for (int j = 1; j <= to; ++j) {
				cin >> nameTo;
				calc(nameTo, m / to);
			}
		}
		for (short i = 0; i < n; ++i)
			printf("%s %d\n", s[i].c_str(), sol[i]);
		newLine = true;
	}
	return 0;
}
