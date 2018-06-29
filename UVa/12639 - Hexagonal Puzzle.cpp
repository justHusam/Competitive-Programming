#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

vector<vector<int> > a;
int arr[7][6], idx[7][7], v[7][6];

bool check(int aa, int bb) {
	// 0
	v[0][2] = arr[a[aa][0]][(bb + 2) % 6];
	v[0][3] = arr[a[aa][0]][(bb + 3) % 6];
	v[0][4] = arr[a[aa][0]][(bb + 4) % 6];
	// 6
	int str = idx[a[aa][6]][v[0][3]];
	for (int i = 0; i < 6; ++i) {
		v[6][i] = arr[a[aa][6]][str];
		str = (str + 1) % 6;
	}
	// 5
	str = idx[a[aa][5]][v[0][4]];
	v[5][1] = arr[a[aa][5]][str];
	v[5][2] = arr[a[aa][5]][(str + 1) % 6];
	v[5][3] = arr[a[aa][5]][(str + 2) % 6];
	if (v[5][2] != v[6][5])
		return false;
	// 1
	str = idx[a[aa][1]][v[6][1]];
	if (str)
		v[1][3] = arr[a[aa][1]][str - 1];
	else
		v[1][3] = arr[a[aa][1]][5];
	v[1][4] = arr[a[aa][1]][str];
	v[1][5] = arr[a[aa][1]][(str + 1) % 6];
	if (v[1][5] != v[0][2])
		return false;
	// 2
	str = idx[a[aa][2]][v[1][3]];
	v[2][4] = arr[a[aa][2]][(str + 4) % 6];
	v[2][5] = arr[a[aa][2]][(str + 5) % 6];
	if (v[2][5] != v[6][2])
		return false;
	// 3
	str = idx[a[aa][3]][v[6][3]];
	v[3][0] = arr[a[aa][3]][str];
	v[3][1] = arr[a[aa][3]][(str + 1) % 6];
	v[3][5] = arr[a[aa][3]][(str + 5) % 6];
	if (v[3][1] != v[2][4])
		return false;
	// 4
	str = idx[a[aa][4]][v[5][3]];
	v[4][0] = arr[a[aa][4]][str];
	v[4][1] = arr[a[aa][4]][(str + 1) % 6];
	v[4][2] = arr[a[aa][4]][(str + 2) % 6];
	return v[4][1] == v[6][4] && v[4][2] == v[3][5];
}

int main(int argc, char **argv) {
	int p[] = { 0, 1, 2, 3, 4, 5, 6 };
	do
		a.push_back(vector<int>(p, p + 7));
	while (next_permutation(p, p + 7));
	while (scanf("%d", &arr[0][0]) > 0) {
		idx[0][arr[0][0]] = 0;
		for (int i = 0; i < 7; ++i)
			for (int j = !i; j < 6; ++j) {
				scanf("%d", &arr[i][j]);
				idx[i][arr[i][j]] = j;
			}
		bool can = false;
		for (size_t i = 0; i < a.size() && !can; ++i)
			for (int j = 0; j < 6 && !can; ++j)
				can |= check(i, j);
		if (can)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
