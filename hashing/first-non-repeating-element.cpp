#include <bits/stdc++.h>
using namespace std;

void firstNonRepeating(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (map[arr[i]] == 1)
        {
            cout << arr[i] << endl;
            return;
        }
    }
    cout << "No non-repeating element" << endl;
    return;
}

int main()
{
    int arr[] = {9, 4, 9, 6, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    firstNonRepeating(arr, n);
    return 0;
}



//To print all non repeating , we should traverse through the unordered_map

