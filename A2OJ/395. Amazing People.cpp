#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		printf("Case %d:\n", k++);
		if (n >= 1 && n <= 5)
			puts("Languages");
		else if (n >= 6 && n <= 7)
			puts("Read and Write");
		else if (n >= 8 && n <= 12)
			puts("Robotics");
		else if (n >= 13 && n <= 19)
			puts("Programming and Robotics");
		else
			puts("Read about everything");
	}
	return 0;
}
