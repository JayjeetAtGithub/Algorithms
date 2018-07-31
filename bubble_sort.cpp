#include <bits/stdc++.h>

using namespace std;

int main() {

    int n , *arr ;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter the elements :";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << "Unsorted array : " ;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "Bubble Sorted Array : ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << "";
    }
    return 0;
}

