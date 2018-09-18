

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll find_min_platforms(ll arr[], ll dep[] , ll n){
	
	ll result = -1;
	ll platforms = 0;
	multimap<ll,char> map;
	for(ll i = 0 ; i < n ; i++){
		map.insert(make_pair(arr[i],'a'));
		map.insert(make_pair(dep[i],'d'));
	}
	for(auto it = map.begin() ; it != map.end() ; it++){
		if(it->second == 'a'){
			platforms++;
		}else if(it->second == 'd'){
			platforms--;
		}
		result = max(result,platforms);
	}
	return result;	
}


int main(){
	ll t , n , *arr , *dep;
	cin >> t;
	while(t--){
		cin >> n;
		arr = new ll[n];
		dep = new ll[n];
		for(ll i = 0 ; i < n ; i++){
			cin >> arr[i];
		}
		for(ll i = 0 ; i < n ; i++){
			cin >> dep[i];
		}
		cout << find_min_platforms(arr,dep,n) << endl;
	}
}


