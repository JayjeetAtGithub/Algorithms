//Naive Recursive Solution
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// i = 0
// 1 indexed array

ll determine(ll arr[], ll n , ll i)
{   
    if(i > n) return 0;
    if(i == n) return arr[i];
    return arr[i] + min(determine(arr , n , i+1) , determine(arr , n , i+2));
}

int main()
{
    ll t, n, *arr;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr = new ll[n+1];
        for(ll i = 1 ; i <= n ; i++){
            cin >> arr[i];
        }
        arr[0] = 0;
        cout << determine(arr , n , 0) << endl;
    }
}

//Dynamic Programming (Memoized Solution)
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000];

ll determine(ll arr[], ll n , ll i)
{   
    if(dp[i] != -1) return dp[i];
    if(i > n) return 0;
    if(i == n) return arr[i];
    dp[i] =  arr[i] + min(determine(arr , n , i+1) , determine(arr , n , i+2));
    return dp[i];
}

int main()
{
    ll t, n, *arr;
    cin >> t;
    while (t--)
    {
        memset(dp , -1 , sizeof(dp));
        cin >> n;
        arr = new ll[n+1];
        for(ll i = 1 ; i <= n ; i++){
            cin >> arr[i];
        }
        arr[0] = 0;
        cout << determine(arr , n , 0) << endl;
    }
}



