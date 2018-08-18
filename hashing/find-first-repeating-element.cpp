#include <bits/stdc++.h>
using namespace std;

int printFirstRepeating(int arr[], int n)
{
    int min = -1;
    set<int> set;
    for (int i = n - 1; i >= 0; i--)
    {
        if (set.find(arr[i]) != set.end())
        {
            min = i;
        }
        else
        {
            set.insert(arr[i]);
        }
    }
    if(min != -1) return arr[min];
    return min;
}

int main()
{
    int arr[] = {10, 6,  5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << printFirstRepeating(arr, n);
}



//To find the last repeating element we have to traverse the array from left to right
//To find the first repeating element we have to traverse the array from right to left

