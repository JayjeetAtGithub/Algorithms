/*
 *
 * Topic : Insertion Sort
 * Name : Jayjeet Chakraborty
 *
 */


#include <bits/stdc++.h>

using namespace std;


void insertion_sort(int arr[] , int n){
    for(int i = 1 ; i < n ; i++){
        int temp = arr[i];
        int j = i - 1; //here we are taking i-1 as j
        while(temp < arr[j] && (j >= 0)){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


int main() {

    int n , *arr;
    cout << "Enter the number of elements to be inserted : " ;
    cin >> n;
    arr = new int[n];
    cout << "Enter the elements of the array : " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    insertion_sort(arr , n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

