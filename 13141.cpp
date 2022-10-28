#include <bits/stdc++.h>
using namespace std;
long long int dp[90];

long long int fib(long long int n){
	if(dp[n] != -1) return dp[n];
	if(n <= 2) return dp[n]= 1;
	return dp[n]= fib(n-1)+fib(n-2);
}

int main(){
	int n;
	while(cin >> n && n){
		memset(dp,-1,sizeof(dp));
		cout << fib(n) << endl;
	}	
}
