/*
 * Name : Jayjeet Chakraborty
 * Topic : Selection Sort
 * Running Time : O(n*n)
 *
 */

#include <bits/stdc++.h>

using namespace std;

int swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int min_element(int arr[] , int k , int n){
    int min = arr[k];
    int pos = k;
    for(int i = k+1 ; i < n ; i++){
        if (arr[i] < min){
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

int selection_sort(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        int min_pos = min_element(arr, i , n);
        swap(arr[min_pos] , arr[i]);
    }
    return 0;
}


int main() {
    int n , *arr;
    cout << "Enter the number of elements of the array : " ;
    cin >> n;
    arr = new int[n];
    cout << "Enter the elements : " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    selection_sort(arr , n);
    cout << "Array sorted using selection sort : " << endl;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

}

