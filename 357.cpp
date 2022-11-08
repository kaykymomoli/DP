#include <bits/stdc++.h>
using namespace std;

int coin[5]={1,5,10,25,50};
long long dp[5][30010];

long long p(int at, int max){
	if(at < 0) return 0;
	if(max == 0) return 1;
	if(dp[at][max] != -1) return dp[at][max];
	long long int pegar= 0, passar= 0;
	if(max - coin[at] >= 0) pegar= p(at,max-coin[at]);
	passar= p(at-1,max);
	return dp[at][max]= passar+pegar;
}

int main(){
	int n;
	while(cin >> n){
		memset(dp,-1,sizeof(dp));
		long long res= p(4,n);
		if(res <= 1){
			cout << "There is only 1 way to produce " << n << " cents change.\n"; 
		}else{
			cout << "There are " << res << " ways to produce " << n << " cents change.\n";
		}
	}
}
