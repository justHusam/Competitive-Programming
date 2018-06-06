#include <bits/stdc++.h>
using namespace std;

int main() {
	int num, max;
	string s;
	cin >> num;
	int f = 0;
	while (num != 0) {
		if (f != 0)
			cout << endl;
		getline(cin, s);
		string *p = new string[num];
		max = (p[0].length());
		for (int i = 0; i < num; i++) {
			getline(cin, p[i]);
			for (; p[i].find(" ") != string::npos;)
				if (p[i] != "")
					p[i] = p[i].erase(p[i].find(' '), 1);
			if ((p[i].length()) > max)
				max = p[i].length();
		}
		for (int i = 0; i < num; i++) {
			int Num = max - (p[i].length());
			for (int j = 0; j < Num; j++)
				cout << " ";
			cout << p[i] << endl;
		}
		f = 1;
		delete[] p;
		cin >> num;
	}
	return 0;
}
