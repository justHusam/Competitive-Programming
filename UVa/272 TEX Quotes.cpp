#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s)) {
		bool cur = true;
		for (size_t i = 0; i < s.length(); ++i) {
			if (s[i] == '"')
				if (cur) {
					s.erase(i, 1);
					s.insert(i, "``");
					cur = !cur;
				} else {
					s.erase(i, 1);
					s.insert(i, "''");
					cur = !cur;
				}
		}
		cout << s << endl;
	}
	return 0;
}
