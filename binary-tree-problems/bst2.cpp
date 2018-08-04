/*
 * Problem : Check if each internal node of a BST has exactly one child
 *
 */

#include <bits/stdc++.h>
#include <array>

using namespace std;


//Time Complexity O(n*n)
bool has_one_child(int arr[] , int n){

    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i+1] > arr[i]) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    continue;
                }
                return false;
            }
        } else {
            for(int j = i + 1 ; j < n ; j++){
                if(arr[j] < arr[i]){
                    continue;
                }
                return false;
            }
        }
    }
    return true;

}



int main(){

    int arr[] = { 8 , 3 , 9 , 7 , 6 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    if(has_one_child(arr , n)){
        cout << "Each internal node has exactly 1 child";
    } else {
        cout << "Nopes";
    }
}




