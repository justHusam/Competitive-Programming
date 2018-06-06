#include <bits/stdc++.h>
using namespace std;

map<string, string> dictionary;
string word, temp, res, s, line;

int main(int argc, char **argv) {
	int n;
	cin >> n;
	while (n-- != 0) {
		cin >> word;
		if (word.length() <= 2) {
			dictionary.insert(make_pair(word, word));
			continue;
		}
		temp = word;
		sort(word.begin() + 1, word.end() - 1);
		dictionary.insert(make_pair(word, temp));
	}
	getline(cin, line);
	while (getline(cin, line)) {
		res = s = "";
		stringstream ss(line);
		while (!ss.eof())
			if (ss >> temp) {
				if (temp.length() <= 2) {
					res += s + temp;
					s = " ";
					continue;
				}
				sort(temp.begin() + 1, temp.end() - 1);
				res += s + dictionary[temp];
				s = " ";
			}
		cout << res << endl;
	}
	return 0;
}
