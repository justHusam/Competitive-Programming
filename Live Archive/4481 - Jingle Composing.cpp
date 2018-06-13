#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int get(char c) {
	char ch[] = { 'W', 'H', 'Q', 'E', 'S', 'T', 'X' };
	int ans = 1;
	for (int i = 0; i < 7; ++i, ans *= 2)
		if (ch[i] == c)
			break;
	return ans;
}

bool check(string &s) {
	map<char, int> freq;
	for (size_t i = 0; i < s.size(); ++i)
		++freq[s[i]];
	map<char, int>::iterator it;
	vector<pair<int, int> > v;
	for (it = freq.begin(); it != freq.end(); ++it) {
		int x = it->second;
		int y = get(it->first);
		int g = __gcd(x, y);
		x /= g;
		y /= g;
		v.push_back(make_pair(x, y));
	}
	while (v.size() > 1) {
		pair<int, int> a = v.back();
		v.pop_back();
		pair<int, int> b = v.back();
		v.pop_back();
		int x = a.first * b.second + a.second * b.first;
		int y = a.second * b.second;
		int g = __gcd(x, y);
		x /= g;
		y /= g;
		v.push_back(make_pair(x, y));
	}
	return v[0].first == v[0].second;
}

int main(int argc, char **argv) {
	string s;
	while (cin >> s && s != "*") {
		vector<int> pos;
		for (size_t i = 0; i < s.size(); ++i)
			if (s[i] == '/')
				pos.push_back(i);
		int res = 0;
		for (size_t i = 1; i < pos.size(); ++i) {
			string a = s.substr(pos[i - 1] + 1, pos[i] - pos[i - 1] - 1);
			if (check(a))
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
