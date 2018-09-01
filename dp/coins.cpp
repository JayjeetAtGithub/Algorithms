#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll getTotal(ll n , ll memo[]){
    if(memo[n]) return memo[n];
    if(n < 12) return n;
    memo[n] = max(n,getTotal(n/2 , memo) + getTotal(n/3 , memo) + getTotal(n/4 , memo));
    return memo[n];
}

int main(){
    ll n;

    while(cin>>n){
        ll *memo = new ll[n];
        cout << getTotal(n,memo) << endl;
    }
}




