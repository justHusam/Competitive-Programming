#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string in;
	while (cin >> in) {
		deque<string> qu;
		string s = "";
		int pos = 0;
		for (size_t i = 0; i < in.length(); ++i) {
			if (in[i] == '[' || in[i] == ']') {
				if (pos == 0)
					qu.push_front(s);
				else
					qu.push_back(s);
				if (in[i] == '[')
					pos = 0;
				else
					pos = 1;
				s = "";
				continue;
			}
			s += in[i];
		}
		if (pos == 0)
			qu.push_front(s);
		else
			qu.push_back(s);
		for (; qu.size(); qu.pop_front())
			printf("%s", qu.front().c_str());
		puts("");
	}
	return 0;
}
