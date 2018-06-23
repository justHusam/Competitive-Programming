#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

string s, ss;
map<string, vector<string> > hs;
vector<char> w;
set<string> st;

int calc(int i) {
	if (i == (int) w.size()) {
		string a = ss;
		sort(a.begin(), a.end());
		if (st.find(a) == st.end()) {
			st.insert(a);
			return hs[a].size();
		}
		return 0;
	}
	int res = calc(i + 1);
	ss.push_back(w[i]);
	res += calc(i + 1);
	ss.pop_back();
	return res;
}

int main(int argc, char **argv) {
	while (cin >> s && s != "#") {
		string a = s;
		sort(a.begin(), a.end());
		hs[a].push_back(s);
	}
	cin.ignore();
	while (getline(cin, s) && s != "#") {
		stringstream ss(s);
		w.clear();
		string a;
		while (ss >> a)
			w.push_back(a[0]);
		st.clear();
		printf("%d\n", calc(0));
	}
	return 0;
}
