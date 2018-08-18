//C++ program to find whether an array is subset of another array or not

#include <bits/stdc++.h>
using namespace std;

bool check(int arr1[] , int arr2[] , int m , int n){
    unordered_set<int> set;
    for(int i = 0 ; i < m ; i++){
        if(set.find(arr1[i]) == set.end()){
            set.insert(arr1[i]);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(set.find(arr2[i]) == set.end()){
            return false;
        }
    }
    return true;
}

int main(){
    int arr1[] = {11, 1, 8, 21, 2, 7};
    int arr2[] = {21, 8, 2, 1};

    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);    

    if(check(arr1, arr2, m, n)){
        cout << 1;
    }else{
        cout << 0;
    }
}



