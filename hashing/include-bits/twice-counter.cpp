#include<bits/stdc++.h>
#define ll long long
using namespace std;

int count_twice_words(string arr[] , int n){
	unordered_map<string,int> map;
	for(int i = 0 ; i < n ; i++){
		map[arr[i]]++;
	}
	int cnt = 0;
	for(auto it = map.begin() ; it != map.end() ; it++){
		if(it->second == 2){
			cnt++;
		}
	}
	return cnt;
}


int main()
{
	int t , n;
	string *arr;
	cin >> t;
	while(t--)
	{
		cin >> n;
		arr = new string[n];
		for(int i = 0 ; i < n ; i++){
			cin >> arr[i]; 
		}
		cout << count_twice_words(arr,n) << endl;
	}
}

