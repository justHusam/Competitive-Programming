#include<bits/stdc++.h>
using namespace std;

inline bool check(const string&s) {
	for (size_t i = 0; i < s.size(); ++i)
		if (isalpha(s[i]))
			return true;
	return false;
}

int main(int argc, char **argv) {
	string s, with;
	set<string> st;
	while (getline(cin, s)) {
		vector<string> v;
		for (size_t i = 0; i < s.size(); ++i) {
			string ss = "";
			while (i < s.size() && (isalpha(s[i]) || s[i] == '-'))
				if (isalpha(s[i]))
					ss += tolower(s[i++]);
				else
					ss += s[i++];
			if (check(ss))
				v.push_back(ss);
		}
		if (v.empty())
			continue;
		int str = 0;
		if (!v.empty()) {
			with += v[0];
			if (with[with.size() - 1] != '-' || v.size() > 1)
				st.insert(with), with = "";
			else if (with[with.size() - 1] == '-' && v.size() == 1)
				with.erase(with.size() - 1);
			++str;
		}
		for (size_t i = str; i < v.size() - 1; ++i)
			st.insert(v[i]);
		if (str != 0 && v.size() == 1)
			continue;
		string temp = v.back();
		if (temp[temp.size() - 1] != '-')
			st.insert(temp);
		else {
			temp.erase(temp.size() - 1);
			with = temp;
		}
	}
	set<string>::iterator it;
	for (it = st.begin(); it != st.end(); ++it)
		cout << *it << "\n";
	return 0;
}
