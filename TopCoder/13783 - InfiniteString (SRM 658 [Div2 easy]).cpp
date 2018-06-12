#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

class InfiniteString {

public:
	string equal(string s, string t) {
		size_t l = (s.size() * t.size()) / __gcd(s.size(), t.size());
		string a = s;
		string b = t;
		while (a.size() != l)
			a += s;
		while (b.size() != l)
			b += t;
		if (a == b)
			return "Equal";
		return "Not equal";
	}
};
