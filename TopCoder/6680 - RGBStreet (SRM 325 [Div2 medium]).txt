#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

class RGBStreet{
public:
	int n;
	int v[20][3];
	int dp[20][3];
	int estimateCost(vector <string> houses){
		n=houses.size();
		for(int a=0;a<n;++a){
			stringstream ss(houses[a]);
			ss>>v[a][0]>>v[a][1]>>v[a][2];
		}
		memset(dp,-1,sizeof dp);
		int res=2e9;
		for(int a=0;a<3;++a)
			res=min(res,calc(0,a));
		return res;
	}
	int calc(int i,int c){
		if(i==n)
			return 0;
		if(dp[i][c]!=-1)
			return dp[i][c];
		int res=2e9;
		for(int a=0;a<3;++a)
			if(c!=a)
				res=min(res,calc(i+1,a));
		return dp[i][c]=v[i][c]+res;
	}
};

int  main(){

#ifndef ONLINE_JUDGE
	freopen("read.txt","r",stdin);
//	freopen("out.txt","w",stdout);
#endif

	return 0 ;
}