#include <bits/stdc++.h>
using namespace std;

map<string, set<string> > st, pr;
map<string, set<string> >::iterator it;
vector<string> v;
vector<pair<int, string> > res;

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s) && s[0] != '0') {
		pr.clear();
		st.clear();
		string p;
		do {
			if (isupper(s[0])) {
				p = s;
				if (pr.find(p) == pr.end())
					pr.insert(make_pair(p, set<string>()));
			} else {
				st[s].insert(p);
				pr[p].insert(s);
			}
			getline(cin, s);
		} while (s[0] != '1');
		v.clear();
		for (it = st.begin(); it != st.end(); ++it)
			if (it->second.size() > 1)
				v.push_back(it->first);
		sort(v.begin(), v.end());
		res.clear();
		for (it = pr.begin(); it != pr.end(); ++it) {
			int in = it->second.size();
			set<string>::iterator jt;
			for (jt = it->second.begin(); jt != it->second.end(); ++jt)
				if (binary_search(v.begin(), v.end(), *jt))
					--in;
			res.push_back(make_pair(-in, it->first));
		}
		sort(res.begin(), res.end());
		for (size_t i = 0; i < res.size(); ++i)
			cout << res[i].second << " " << -res[i].first << "\n";
	}
	return 0;
}
