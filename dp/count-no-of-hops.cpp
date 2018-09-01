#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll dp[100001];

ll rec()
{
    dp[0] = 1;
    dp[1] = 1;
    for(ll i = 2 ; i < 100001 ; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%mod;
    }
}


int main()
{
    ll t;
    cin>>t;
    rec();
    while(t--)
    {
        ll n;
        cin >> n;
        cout<<dp[n]<<endl;
    }
    return 0;
}

