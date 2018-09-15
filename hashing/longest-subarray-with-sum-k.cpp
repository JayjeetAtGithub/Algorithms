#include<bits/stdc++.h>
#define ll long long
using namespace std;



int count_longest_subarray(int arr[] , int n , int k){
	unordered_map<int,int> set;
	int sum = 0;
	int max_length = 0;
	for(int i = 0 ; i < n ; i++){
		sum += arr[i];
		if(sum == k){
			max_length = i+1;
		}
		if(set.find(sum-k) != set.end()){
			max_length = max(max_length,i-set[sum-k]);
		}
		//finds the first non-repeating sum
		if(set.find(sum) == set.end()){
			set[sum] = i;
		}
	}
	return max_length;
}


int main()
{
	int t , n , k;
	int *arr;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		arr = new int[n+1];
		for(int i = 0 ; i < n ; i++){
			cin >> arr[i]; 
		}
		cout << count_longest_subarray(arr,n,k) << endl;
	}
}

