#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string s;
	vector<pair<string, string> > v;
	while (cin >> s && s != "XXXXXX") {
		string z = s;
		sort(z.begin(), z.end());
		v.push_back( { z, s });
	}
	sort(v.begin(), v.end());
	string E = "";
	while (cin >> s && s != "XXXXXX") {
		sort(s.begin(), s.end());
		size_t k = lower_bound(v.begin(), v.end(), make_pair(s, E)) - v.begin();
		if (k == v.size() || v[k].first != s)
			puts("NOT A VALID WORD");
		else {
			while (k < v.size() && v[k].first == s)
				puts(v[k++].second.c_str());
		}
		puts("******");
	}
	return 0;
}
