#include <bits/stdc++.h>
#include <array>

using namespace std;

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[] , int index , int n){
        int i = index; //index where new element is inserted
        int pos = i;
        while(pos > 0){
            int par = (pos-1)/2;
            if(arr[pos] > arr[par]){
                swap(arr[pos] , arr[par]);
            }
            else{
                return;
            }
            pos = par;
        }
}


void de_heapify(int arr[],int i , int n){

    int left = 2*i + 1;
    int right = left + 1;
    int largest = -1;
    if (left < n && arr[left] > arr[i]){
        largest = left;
    } else {
        largest = i;
    }

    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest] , arr[i]);
        de_heapify(arr , largest , n);
    }
}


int main(){

    int n , *arr;
    cout << "Enter the number of elements : ";
    cin >> n;
    int size = n;
    arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    //Build the heap from the array
    for(int i = 0 ; i < n ; i++){
       max_heapify(arr,i,n);
    }

    //Display heap
    for(int i = 0 ; i < n ; i++){
        cout << "Val : " << arr[i] << "\n";
    }

    cout << "Heap Sort : \n";
    for(int i = n-1 ; i > 0 ; i--) {
        swap(arr[0],arr[i]);
        size = size - 1;
        de_heapify(arr, 0 , size);
    }

    for(int i = 0 ; i < n ; i++){
        cout << "Val : " << arr[i] << "\n";
    }

    return  0;
}



