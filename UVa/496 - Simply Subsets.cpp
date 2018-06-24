#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

vector<int> A, B;

vector<int> get(string &s) {
	stringstream ss(s);
	int x;
	vector<int> v;
	while (ss >> x)
		v.push_back(x);
	sort(v.begin(), v.end());
	return v;
}

bool equals() {
	if (A.size() != B.size())
		return false;
	for (size_t i = 0; i < A.size(); ++i)
		if (A[i] != B[i])
			return false;
	return true;
}

bool disjoint() {
	for (size_t i = 0; i < A.size(); ++i)
		if (binary_search(B.begin(), B.end(), A[i]))
			return false;
	return true;
}

bool AinB() {
	for (size_t i = 0; i < A.size(); ++i)
		if (!binary_search(B.begin(), B.end(), A[i]))
			return false;
	return true;
}

bool BinA() {
	for (size_t i = 0; i < B.size(); ++i)
		if (!binary_search(A.begin(), A.end(), B[i]))
			return false;
	return true;
}

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s)) {
		A = get(s);
		getline(cin, s);
		B = get(s);
		if (equals()) {
			puts("A equals B");
			continue;
		}
		if (disjoint()) {
			puts("A and B are disjoint");
			continue;
		}
		bool in1 = AinB();
		bool in2 = BinA();
		if (in1 && !in2) {
			puts("A is a proper subset of B");
			continue;
		}
		if (in2 && !in1) {
			puts("B is a proper subset of A");
			continue;
		}
		puts("I'm confused!");
	}
	return 0;
}
