#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	map<char, char> hs;
	hs['A'] = 'V';
	hs['B'] = 'W';
	hs['C'] = 'X';
	hs['D'] = 'Y';
	hs['E'] = 'Z';
	hs['F'] = 'A';
	hs['G'] = 'B';
	hs['H'] = 'C';
	hs['I'] = 'D';
	hs['J'] = 'E';
	hs['K'] = 'F';
	hs['L'] = 'G';
	hs['M'] = 'H';
	hs['N'] = 'I';
	hs['O'] = 'J';
	hs['O'] = 'J';
	hs['P'] = 'K';
	hs['Q'] = 'L';
	hs['R'] = 'M';
	hs['S'] = 'N';
	hs['T'] = 'O';
	hs['U'] = 'P';
	hs['V'] = 'Q';
	hs['W'] = 'R';
	hs['X'] = 'S';
	hs['Y'] = 'T';
	hs['Z'] = 'U';
	string s;
	while (cin >> s && s != "ENDOFINPUT") {
		cin.ignore();
		getline(cin, s);
		string res = "";
		for (size_t i = 0; i < s.size(); ++i)
			if (hs.find(s[i]) != hs.end())
				res += hs[s[i]];
			else
				res += s[i];
		cin >> s;
		cout << res << "\n";
	}
	return 0;
}
