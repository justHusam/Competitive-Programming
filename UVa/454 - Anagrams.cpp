#include<bits/stdc++.h>
#include<map>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

inline string get(const string &s) {
	string temp;
	for (size_t i = 0; i < s.size(); ++i)
		if (s[i] != ' ')
			temp += s[i];
	sort(temp.begin(), temp.end());
	return temp;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	cin.ignore();
	string s;
	getline(cin, s);
	while (T-- != 0) {
		vector<pair<string, string> > v, res;
		while (getline(cin, s) && s.length())
			v.push_back(make_pair(s, get(s)));
		for (size_t i = 0; i < v.size(); ++i)
			for (size_t j = i + 1; j < v.size(); ++j)
				if (v[i].second == v[j].second) {
					if (v[i].first < v[j].first)
						res.push_back(make_pair(v[i].first, v[j].first));
					else
						res.push_back(make_pair(v[j].first, v[i].first));
				}
		sort(res.begin(), res.end());
		for (size_t i = 0; i < res.size(); ++i)
			printf("%s = %s\n", res[i].first.c_str(), res[i].second.c_str());
		if (T != 0)
			puts("");
	}
	return 0;
}
