#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[22];
map<string, int> freq;
vector<string> v, sol;

inline string calc(const string &s) {
	string z = s;
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = tolower(z[i]);
	sort(z.begin(), z.end());
	return z;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) != EOF && s[0] != '#') {
		v.push_back(s);
		++freq[calc(s)];
	}
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i].size() == 1) {
			sol.push_back(v[i]);
			continue;
		}
		string z = calc(v[i]);
		if (freq[z] == 1)
			sol.push_back(v[i]);
	}
	sort(sol.begin(), sol.end());
	for (size_t i = 0; i < sol.size(); ++i)
		puts(sol[i].c_str());
	return 0;
}
