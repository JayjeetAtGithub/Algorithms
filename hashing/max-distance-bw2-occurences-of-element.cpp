#include <bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n)
{
    int max = INT_MIN;
    unordered_map<int, int> index;
    unordered_map<int,int> diff;
    for (int i = 0; i < n; i++)
    {
        if (index.find(arr[i]) != index.end())
        {
            diff[arr[i]] = i - index[arr[i]];
        }
        else
        {
           index[arr[i]] = i;
           diff[arr[i]] = 0;
        }
    }
    for (auto it = diff.begin(); it != diff.end(); it++)
    {
        if (it->second > max)
        {
            max = it->second;
        }
    }
    return max;
}


int main()
{
    //int arr[] = {93, 2, 1, 3, 1, 4, 5, 8, 19, 7, 9, 3};
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxDistance(arr, n);
    return 0;
}

