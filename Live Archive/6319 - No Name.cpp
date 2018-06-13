#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T, XY;
	string s, r, IP;
	cin >> T;
	while (T-- != 0) {
		cin >> s;
		while (true) {
			cin >> IP;
			if (IP == "END")
				break;
			cin >> r >> XY;
			if (IP[0] == 'I') {
				string temp = s.substr(0, XY) + r;
				if (XY < (int) s.length())
					temp += s.substr(XY, s.length() - XY);
				s = temp;
			} else {
				int x = atoi(r.c_str());
				cout << s.substr(x, XY - x + 1) << "\n";
			}
		}
	}
	return 0;
}
