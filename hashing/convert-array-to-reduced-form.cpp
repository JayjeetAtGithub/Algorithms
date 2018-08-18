#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void convert(int arr[] , int n)
{
    int *temp = new int[n];
    for(int i=0 ; i < n ; i++){
        temp[i] = arr[i];
    }
    unordered_map<int,int> map;
    sort(temp,temp+n);
    for(int i = 0 ; i < n ; i++){
        map[temp[i]] = i;
    }
    for(int i = 0 ; i < n ; i++){
        arr[i] = map[arr[i]];
    }
}


int main()
{
    int arr[] = {10, 20, 15, 12, 11, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given Array is \n";
    printArr(arr, n);

    convert(arr, n);

    cout << "\n\nConverted Array is \n";
    printArr(arr, n);

    return 0;
}


