#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	string s;
	set<string> st, res;
	while (cin >> s)
		st.insert(s);
	set<string>::iterator it;
	for (it = st.begin(); it != st.end(); ++it) {
		s = *it;
		for (size_t i = 1; i < s.size(); ++i) {
			string x = s.substr(0, i);
			string y = s.substr(i);
			if (st.find(x) != st.end() && st.find(y) != st.end()) {
				res.insert(s);
				break;
			}
		}
	}
	for (it = res.begin(); it != res.end(); ++it)
		cout << *it << "\n";
	return 0;
}
