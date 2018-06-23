#include <bits/stdc++.h>
using namespace std;

unordered_set<string> hs;

int BFS(string str, string dest) {
	queue<string> qu;
	string temp, ch;
	unordered_map<string, int> cost;
	if (str == dest)
		return 0;
	for (unordered_set<string>::iterator it = hs.begin(); it != hs.end(); ++it)
		cost.insert( { *it, 0 });
	qu.push(str);
	cost[temp] = 0;
	while (!qu.empty()) {
		string v = qu.front();
		qu.pop();
		for (size_t i = 0; i < v.size(); ++i) {
			string ch = v;
			for (int j = 0; j < 26; ++j) {
				ch[i] = char(97 + j);
				if (hs.find(ch) != hs.end() && cost[ch] == 0 && ch != str) {
					qu.push(ch);
					cost[ch] = cost[v] + 1;
					if (ch == dest)
						return cost[dest];
				}
			}
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	cin.ignore();
	string s, u, v;
	while (T-- != 0) {
		hs.clear();
		while (getline(cin, s) && s[0] != '*')
			hs.insert(s);
		while (getline(cin, s) && s != "") {
			stringstream ss(s);
			ss >> u >> v;
			printf("%s %s %u\n", u.c_str(), v.c_str(), BFS(u, v));
		}
		if (T != 0)
			puts("");
	}
	return 0;
}
