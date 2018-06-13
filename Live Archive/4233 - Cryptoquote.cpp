#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	map<char, char> hs;
	cin >> T;
	cin.ignore();
	for (int it = 1; it <= T; ++it) {
		string eM, ch, dM;
		getline(cin, eM);
		getline(cin, ch);
		for (char i = 'A'; i <= 'Z'; i++)
			hs[i] = ch[i - 65];
		hs[' '] = ' ';
		for (int i = 0; i < eM.length(); i++)
			dM += hs[eM[i]];
		cout << it << " " << dM << endl;
	}
	return 0;
}
