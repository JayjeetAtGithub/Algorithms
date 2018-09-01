#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll seq(ll n , ll arr[]){

    if(arr[n] != 0){
        return arr[n];
    }

    if(n <= 2){
        arr[n] = 1;
        return arr[n];
    }

    arr[n] = seq(n-2 , arr) + seq(n-3 , arr);
    return arr[n];
}


int main(){

    ll t , n;
    cin >> t;
    while(t--){
        cin >> n;
        ll *arr = new ll[n+1];
        seq(n,arr);
        cout << (arr[n] % 1000000007);
        cout << endl;
    }
}


