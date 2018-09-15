#define ll long long
using namespace std;

bool check_zero_sum_subarray(int arr[] , int n){
	unordered_set<int> set;
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum = sum + arr[i];
		if(sum == 0 || set.find(sum) != set.end()){
			return true;
		}else{
			set.insert(sum);
		}
	}
	return false;
}


int main()
{
	int t , n , *arr;
	cin >> t;
	while(t--)
	{
		cin >> n;
		arr = new int[n];
		for(int i = 0 ; i < n ; i++){
			cin >> arr[i]; 
		}
		if(check_zero_sum_subarray(arr,n)){
		    cout << "Yes" << endl;
		}else{
		    cout << "No" << endl;
		}
	}
}

