#include <bits/stdc++.h>
using namespace std;

int dolar[11]={5, 10, 20, 50,100,200,500,1000,2000,5000,10000};
long long dp[12][30010];

long long p(int at, int max){
	if(at < 0) return 0;
	if(max == 0) return 1;
	if(dp[at][max] != -1) return dp[at][max];
	long long pegar= 0, passar= 0;
	if(max - dolar[at] >= 0) pegar= p(at,max-dolar[at]);
	passar= p(at-1, max);
	return dp[at][max]= pegar+passar;
}

int main(){
	float n;
	while(cin >> n && n){
		memset(dp,-1,sizeof(dp));
		n = n*10000;
		n = n/100;
		cout << fixed << setprecision(2);
		cout << setw(6)<<setfill(' ') << n/100;
		cout << setw(17)<< setfill(' ') << p(10,n)<< endl;
		//~ printf("%6.2f %17llx \n", n/100, p(10,n));
	}
}
