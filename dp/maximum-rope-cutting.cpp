//Recursion and Memoization (Dynamic Programming)
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mem[109];

ll max(ll a, ll b) { return (a > b) ? a : b; }
ll max(ll a, ll b, ll c) { return max(a, max(b, c)); };

ll maxProd(ll n)
{
    if (mem[n])
        return mem[n];
    if (n == 1 || n == 0)
        return 0;
    ll max_val = 0;
    for (ll i = 1; i < n; i++)
    {
        max_val = max(max_val, i * (n - i), maxProd(n - i) * i);
    }
    mem[n] = max_val;
    return mem[n];
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        memset(mem, 0, sizeof(mem));
        cin >> n;
        cout << maxProd(n) << endl;
    }
    return 0;
}

