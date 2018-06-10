#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	vector<char> st;
	string s, res;
	cin >> T;
	while (T-- != 0) {
		res = "";
		cin >> s;
		for (size_t i = 0; i < s.length(); ++i) {
			if (isalpha(s[i]))
				res += s[i];
			else if (s[i] == ')') {
				while (st.back() != '(') {
					res += st.back();
					st.pop_back();
				}
				st.pop_back();
			}
			else
				st.push_back(s[i]);
		}
		puts(res.c_str());
	}
	return 0;
}
