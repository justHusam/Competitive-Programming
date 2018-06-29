#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
	vector<char> st;
	for (size_t i = 0; i < s.length(); ++i)
		if (s[i] == '(' || s[i] == '[')
			st.push_back(s[i]);
		else if (s[i] == ')' || s[i] == ']') {
			if (st.empty())
				return false;
			if (s[i] == ')' && st.back() != '(')
				return false;
			if (s[i] == ']' && st.back() != '[')
				return false;
			st.pop_back();
		}
	return st.empty();
}

int main(int argc, char **argv) {
	int T;
	string s;
	cin >> T;
	cin.ignore();
	while (T-- != 0) {
		getline(cin, s);
		if (s.length() == 0 || check(s))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
