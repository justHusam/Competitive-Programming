#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	cin >> T;
	cin.ignore();
	while (T-- != 0) {
		string s, r;
		getline(cin, s);
		vector<string> v;
		set<string> st;
		stringstream ss(s);
		while (ss >> r) {
			v.push_back(r);
			st.insert(r);
		}
		while (getline(cin, s) && s != "what does the fox say?") {
			stringstream ss(s);
			for (int i = 0; i < 3; ++i)
				ss >> r;
			st.erase(r);
		}
		bool sp = false;
		for (string &s : v)
			if (st.find(s) != st.end()) {
				if (sp)
					printf(" ");
				sp = true;
				printf("%s", s.c_str());
			}
		puts("");
	}
	return 0;
}
