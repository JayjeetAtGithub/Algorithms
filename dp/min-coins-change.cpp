/* 
 Q.Given an amount N and infinite supply of denominations C1,C2,C3,C4....., Find out
 the minimmum number of coins required to make up the value of N.
*/

//Dynamic Programming (Using 1D array)

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void record(ll arr[], ll n, ll v)
{
    ll dp[v + 1];
    dp[0] = 0;
    for (int i = 1; i <= v; i++)
    {
        dp[i] = INT_MAX;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j < v + 1; j++)
        {
            if (j >= arr[i])
            {
                dp[j] = min(dp[j], 1 + dp[j - arr[i]]);
            }
        }
    }
    if (dp[v] != INT_MAX)
    {
        cout << dp[v] << endl;
        return;
    }
    cout << -1 << endl;
    return;
}

int main()
{
    ll t, n, v, *arr;
    cin >> t;
    while (t--)
    {
        cin >> v >> n;
        arr = new ll[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        record(arr, n, v);
    }
}



