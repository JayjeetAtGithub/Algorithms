#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int todigit(char ch){
    return (ch - '0');
}


int sumofallsubstrings(string num){
    int n = num.length();
    int sumofdigits[n];
    sumofdigits[0] = todigit(num[0]);
    int res = sumofdigits[0];
    for(int i = 1 ; i < n ; i++){
        int numi = todigit(num[i]);
        sumofdigits[i]  =  (i+1)*numi + 10*sumofdigits[i-1];
        res += sumofdigits[i];
    }
    return res;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sumofallsubstrings(s) << endl;
    }
}

