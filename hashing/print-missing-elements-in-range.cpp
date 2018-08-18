#include <bits/stdc++.h>
using namespace std;

void printMissing(int arr[], int n, int low, int high)
{
    unordered_map<int,int> map;
    for(int i = 0 ; i < n ; i++){
        map[arr[i]]++;
    }
    for(int i = low ; i <= high ; i++){
        if(map.find(i) == map.end()){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 1, high = 10;
    printMissing(arr, n, low, high);
    return 0;
}


