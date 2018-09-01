#include <bits/stdc++.h>
#define ll long long
using namespace std;

int longest_increasing_subsequence(int arr[] , int n){
    int *lis;
    lis = new int[n];
    for(int i = 0 ; i < n ; i++){
        lis[i] = 1;
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    int max = 0;
    for(int i = 0 ; i < n ; i++){
        if(lis[i] > max){
            max = lis[i];
        }
    }
    free(lis);
    return max;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,22,9,33,21,50,41,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << longest_increasing_subsequence(arr,n);
    return 0;
}


