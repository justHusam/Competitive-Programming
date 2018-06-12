#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class WordAbbreviation {
public:
	vector<vector<int> > g;
	vector<int> freq;

	vector<string> getAbbreviations(vector<string> words) {
		g.push_back(vector<int>(26, -1));
		freq.push_back(0);
		for (size_t i = 0; i < words.size(); ++i)
			insert(words[i]);
		vector<string> res;
		for (size_t i = 0; i < words.size(); ++i)
			res.push_back(words[i].substr(0, find(words[i])));
		return res;
	}

	void insert(string &s) {
		int cur = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			if (g[cur][s[i] - 'a'] == -1) {
				g[cur][s[i] - 'a'] = g.size();
				g.push_back(vector<int>(26, -1));
				freq.push_back(0);
			}
			cur = g[cur][s[i] - 'a'];
			++freq[cur];
		}
	}

	int find(string &s) {
		int cur = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			if (freq[cur] == 1)
				return i;
			cur = g[cur][s[i] - 'a'];
		}
		return s.size();
	}
};
