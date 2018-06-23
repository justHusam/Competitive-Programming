#include <bits/stdc++.h>
using namespace std;

vector<string> kL, eL;
vector<int> v;

int calc(string s) {
	int res = 0;
	for (size_t i = 0; i < s.length(); ++i) {
		string temp = "";
		while (isalpha(s[i]))
			temp += tolower(s[i++]);
		for (size_t j = 0; j < kL.size() && temp != ""; j++)
			if (temp == kL[j])
				++res;
	}
	return res;
}

int main(int argc, char **argv) {
	int n, m;
	for (int caseN = 1; cin >> n >> m; ++caseN) {
		kL.clear();
		kL.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> kL[i];
		cin.ignore();
		eL.clear();
		eL.resize(m);
		v.clear();
		for (int i = 0; i < m; ++i) {
			getline(cin, eL[i]);
			v[i] = calc(eL[i]);
		}
		int mx = 0;
		for (size_t i = 0; i < v.size(); ++i)
			mx = max(mx, v[i]);
		printf("Excuse Set #%d\n", caseN);
		for (int i = 0; i < v.size(); ++i)
			if (v[i] == mx)
				puts(eL[i].c_str());
		puts("");
	}
	return 0;
}
