#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	string s;
	int k = 1;
	while (cin >> s) {
		int res = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			if ((res & 1) == 0 && s[i] == '1')
				++res;
			else if ((res & 1) == 1 && s[i] == '0')
				++res;
		}
		printf("Game #%d: %d\n", k++, res);
	}
	return 0;
}
