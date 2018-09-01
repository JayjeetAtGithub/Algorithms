//Coin Change problem

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll play(ll arr[], ll n, ll k)
{
    ll count[k + 1];
    memset(count, 0, sizeof(count));
    count[0] = 1;
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 1 ; j < k + 1 ; j++)
        {
            if (j >= arr[i])
            {
                count[j] += count[j - arr[i]];
            }
        }
    }
    return count[k];
}


int main()
{
    ll t, *arr, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        arr = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << play(arr, n, k) << endl;
        if (play(arr, n, k) > 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}


