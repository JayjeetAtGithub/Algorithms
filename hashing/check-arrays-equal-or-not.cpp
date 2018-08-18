#include <bits/stdc++.h>
using namespace std;

bool areEqual(int arr1[] , int arr2[] , int n , int m){
    unordered_map<int,int> map;

    for(int i = 0 ; i < n ; i++){
        map[arr1[i]]++;
    }

    for(int i = 0 ; i < m ; i++){
        if(map.find(arr2[i]) == map.end()){
            return false;
        }

        if(map[arr2[i]] == 0){
            return false;
        }

        map[arr2[i]]--;
    }
}


int main()
{
    int arr1[] = { 3, 5, 2, 5, 2};
    int arr2[] = { 2, 3, 5, 5, 2};
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);
 
    if (areEqual(arr1, arr2, n, m))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

