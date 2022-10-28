#include <bits/stdc++.h>
using namespace std;

int pd[5][8000];
int cent[5]={1,5,10,25,50};

int dp(int at, int max){
	if(at < 0) return 0;
	if(max == 0) return 1;
	if(pd[at][max] != -1) return pd[at][max];
	int pegar= 0, passar= 0;
	if(max - cent[at] >= 0) pegar= dp(at, max-cent[at]);
	passar= dp(at-1,max);
	return pd[at][max]= pegar+passar;
}

int main(){
	int n;
	while(cin >> n){
		memset(pd,-1,sizeof(pd));
		cout << dp(4, n) << endl;
	}	
}
