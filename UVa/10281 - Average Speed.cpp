#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	string s;
	int speed = -1, before = 0;
	double all = 0;
	while (getline(cin, s)) {
		int cH = atoi(s.substr(0, 2).c_str());
		int cM = atoi(s.substr(3, 2).c_str());
		int cS = atoi(s.substr(6, 2).c_str());
		int current = cH * 3600 + cM * 60 + cS;
		int d = current - before;
		double t = speed / 3600.0 * d;
		all += t;
		int sp = s.find(' ');
		if (sp == string::npos)
			printf("%s %.2lf km\n", s.c_str(), all + 1e-3);
		else
			speed = atoi(s.substr(sp + 1).c_str());
		before = current;
	}
	return 0;
}