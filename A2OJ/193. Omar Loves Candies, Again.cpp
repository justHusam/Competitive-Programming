#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		string s;
		cin >> s;
		map<char, int> hs;
		for (int a = 0; a < (int) s.length(); ++a)
			++hs[s[a]];
		vector<pair<int, char> > v;
		map<char, int>::iterator it;
		for (it = hs.begin(); it != hs.end(); ++it) {
			int f = it->second;
			char s = it->first;
			v.push_back(make_pair(-f, s));
		}
		sort(v.begin(), v.end());
		cout << v[0].first * -1 << " " << v[0].second << endl;
	}
	return 0;
}
