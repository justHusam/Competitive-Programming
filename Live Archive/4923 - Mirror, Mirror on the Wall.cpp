#include <bits/stdc++.h>
using namespace std;

string s;

int main(int argc, char **argv) {
	while (cin >> s && s[0] != '#') {
		string res = "";
		reverse(s.begin(), s.end());
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == 'b')
				res += 'd';
			else if (s[i] == 'd')
				res += 'b';
			else if (s[i] == 'p')
				res += 'q';
			else if (s[i] == 'q')
				res += 'p';
			else if (s[i] == 'i' || s[i] == 'o' || s[i] == 'v' || s[i] == 'w' || s[i] == 'x')
				res += s[i];
			else {
				res = "INVALID";
				break;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
