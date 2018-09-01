#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[20];
void rec(){
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3 ; i <= 20 ; i++){
        dp[i] = ((dp[i-2])*(dp[i-2])) - dp[i-1];
    }
}

int main(){
    int t , n;
    cin >> t;
    rec();
    while(t--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cout << dp[i] << " ";
        }
        cout << endl;
    }
}


