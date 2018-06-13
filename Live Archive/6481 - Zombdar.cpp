#include <bits/stdc++.h>
using namespace std;

vector<string> v;

string get(const string &s) {
	string w = "";
	for (size_t i = 0; i < s.size(); ++i)
		if (isalpha(s[i]) || isdigit(s[i]) || s[i] == ':' || s[i] == ';')
			w += s[i];
	if (w[0] == 'N')
		return "No Zombies;";
	if (w[0] == 'Z') {
		string res = "Zombies";
		int k = w.find(":");
		res += ": ";
		res += w.substr(k + 1);
		return res;
	}
	return "RUN;";
}

int main(int argc, char **argv) {
	int t;
	cin >> t;
	cin.ignore();
	while (t-- != 0) {
		v.clear();
		string s;
		while (getline(cin, s) && s != "END OF CASE")
			v.push_back(s);
		string w = "";
		int at = 1;
		for (size_t i = 0; i < v.size(); ++i) {
			for (size_t j = 0; j < v[i].size(); ++j) {
				w += v[i][j];
				if (v[i][j] == ';') {
					cout << at << ": " << get(w) << "\n";
					w = "";
				}
			}
			++at;
		}
	}
	return 0;
}
