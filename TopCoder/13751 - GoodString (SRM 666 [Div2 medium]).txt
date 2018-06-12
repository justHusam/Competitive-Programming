#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class GoodString {
public:
	string isGood(string s) {
		vector<char> st;
		for (size_t i = 0; i < s.size(); ++i) {
			if (!st.empty() && st.back() == 'a' && s[i] == 'b')
				st.pop_back();
			else
				st.push_back(s[i]);
		}
		if (st.size() == 0)
			return "Good";
		return "Bad";
	}
};
