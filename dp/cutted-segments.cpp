#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[4005];

int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(a, max(b, c)); }

int f(int remLen, vector<int> &dp, int x, int y, int z) {
    if (remLen==0) return 0;
    if (remLen < 0) return INT_MIN;
    if (dp[remLen] == -1) {
        dp[remLen] = max(1+f(remLen-x, dp, x, y, z),1+f(remLen-y, dp, x, y, z),1+f(remLen-z, dp, x, y, z));
    }
    return dp[remLen];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, x, y, z;
	    cin >> n >> x >> y >> z;
	    vector<int> dp(n+1);
	    for (int i=0; i < n+1; i++) dp[i] = -1;
	    cout << f(n, dp, x, y, z) << "\n";
	}
	return 0;
}



// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;
// ll dp[4005];

// int max(int a, int b) { return (a > b) ? a : b; }
// int max(int a, int b, int c) { return max(a, max(b, c)); }

// int f(int remLen, vector<int> &dp, int x, int y, int z)
// {
//     if (dp[remLen] != -1)
//         return dp[remLen];
//     if (remLen == 0)
//         return 0;
//     if (remLen < 0)
//         return INT_MIN;

//     dp[remLen] = max(1 + f(remLen - x, dp, x, y, z), 1 + f(remLen - y, dp, x, y, z), 1 + f(remLen - z, dp, x, y, z));
//     return dp[remLen];
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, x, y, z;
//         cin >> n >> x >> y >> z;
//         vector<int> dp(n + 1);
//         for (int i = 0; i < n + 1; i++)
//             dp[i] = -1;
//         cout << f(n, dp, x, y, z) << "\n";
//     }
//     return 0;
// }
