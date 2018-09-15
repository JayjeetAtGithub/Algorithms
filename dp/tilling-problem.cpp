#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100];

ll count_ways(ll n){

	dp[0] = 0;
	if(dp[n] != -1){
		return dp[n];
	}
	if (n==1 || n==2 || n==3) {
		dp[n] = 1;
		return dp[n];
	}
	if(n == 4){
		dp[n] = 2;
		return dp[n];
	}
	dp[n] = count_ways(n-1) + count_ways(n-4);
	return dp[n];
}

int main(){
	for(int i = 0 ; i < 100 ; i++){
		dp[i] = -1;
	}
	ll t , n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << count_ways(n) << endl;

	}
}

