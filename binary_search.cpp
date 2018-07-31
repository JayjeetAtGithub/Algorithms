//Binary Search

#include <bits/stdc++.h>
using namespace std;


int b_search(int arr[] , int num , int left , int right){
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == num){
            return num;
        }
        if(num < arr[mid]){
            right = mid-1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}


int main(){

    int num;
    int arr[] = { 4 ,  6, 8 ,10 , 89 , 99 };
    int size = sizeof(arr)/ sizeof(arr[0]);
    cin >> num;
    int res = b_search(arr,num,0,size-1);
    if(res == num && res != -1){
        cout << "Found";
    }else{
        cout << "Not Found";
    }

}


