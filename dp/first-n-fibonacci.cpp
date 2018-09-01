#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll fib(ll n , ll arr[]){

    if(arr[n] != 0){
        return arr[n];
    }

    if(n <= 2){
        arr[n] = 1;
        return arr[n];
    }

    arr[n] = fib(n-1 , arr) + fib(n-2 , arr);
    return arr[n];
}


int main(){

    ll t , n;
    cin >> t;
    while(t--){
        cin >> n;
        ll *arr = new ll[n+1];
        fib(n,arr);
        for(ll i = 1 ; i < n+1 ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
