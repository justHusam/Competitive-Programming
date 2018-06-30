#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	map<string, string> hs;
	string s;
	while (getline(cin, s) && !s.empty()) {
		stringstream ss(s);
		string a, b;
		ss >> a >> b;
		hs[b] = a;
	}
	while (cin >> s) {
		if (hs.find(s) == hs.end())
			puts("eh");
		else
			puts(hs[s].c_str());
	}
	return 0;
}
