#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e6;
char s[N];
vector<string> v;
map<string, int> hs;

inline int calc(int str, int tar) {
	int res = 0;
	for (int i = str; i < tar; ++i) {
		int x = hs[v[i]];
		if (x < 100)
			res += x;
		else
			res *= x;
	}
	return res;
}

int main(int argc, char **argv) {
	hs["zero"] = 0;
	hs["one"] = 1;
	hs["two"] = 2;
	hs["three"] = 3;
	hs["four"] = 4;
	hs["five"] = 5;
	hs["six"] = 6;
	hs["seven"] = 7;
	hs["eight"] = 8;
	hs["nine"] = 9;
	hs["ten"] = 10;
	hs["eleven"] = 11;
	hs["twelve"] = 12;
	hs["thirteen"] = 13;
	hs["fourteen"] = 14;
	hs["fifteen"] = 15;
	hs["sixteen"] = 16;
	hs["seventeen"] = 17;
	hs["eighteen"] = 18;
	hs["nineteen"] = 19;
	hs["twenty"] = 20;
	hs["thirty"] = 30;
	hs["forty"] = 40;
	hs["fifty"] = 50;
	hs["sixty"] = 60;
	hs["seventy"] = 70;
	hs["eighty"] = 80;
	hs["ninety"] = 90;
	hs["hundred"] = 100;
	hs["thousand"] = 1000;
	hs["million"] = 1000000;
	while (gets(s) > 0) {
		v.clear();
		stringstream ss(s);
		string temp;
		while (ss >> temp)
			v.push_back(temp);
		size_t idx = 0;
		int res = 0, g = 1;
		if (v[idx] == "negative") {
			g = -1;
			++idx;
		}
		for (size_t i = idx; i < v.size(); ++i)
			if (v[i] == "million") {
				res += calc(idx, i) * 1e6;
				idx = i + 1;
				break;
			}
		for (size_t i = idx; i < v.size(); ++i)
			if (v[i] == "thousand") {
				res += calc(idx, i) * 1e3;
				idx = i + 1;
				break;
			}
		res += calc(idx, v.size());
		printf("%d\n", res * g);
	}
	return 0;
}
