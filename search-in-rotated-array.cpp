#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll find_pivot(ll arr[] , ll n){
	for(ll i = 1 ; i < n-1 ; i++){
		if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
			return i;
		}
		else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){
			return i;
		}
	}
	return -1;
}

ll binary_search(ll arr[] , ll beg , ll end , ll k){
	while(beg <= end){
		ll mid = (beg+end)/2;
		if(arr[mid] == k){
			return mid;
		}
		else if(k > arr[mid]){
			beg = mid+1;
		}
		else
		{
			end = mid-1;
		}

	}
	return -1;
}

ll custom_search(ll arr[] , ll n , ll k){
	ll pivot = find_pivot(arr,n);
	cout << pivot << endl;
	if (arr[pivot] == k) return pivot;
	ll pos_left = binary_search(arr,0,pivot-1,k);
	ll pos_right = binary_search(arr,pivot+1,n-1,k);
	if(pos_left != -1 && pos_right == -1) {
		return pos_left;
	}
	else if(pos_right != -1 && pos_left == -1){
		return pos_right;
	}
	else{
		return -1;
	}
}

int main()
{
	ll t , n , *arr , k;
	cin >> t;
	while(t--)
	{
		cin >> n;
		arr = new ll[n];
		for(ll i = 0 ; i < n ; i++)
		{
			cin >> arr[i];
		}
		cin >> k;
		cout << custom_search(arr,n,k) << endl;
	}
}

