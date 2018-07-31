//Linear Search
#include <bits/stdc++.h>

using namespace std;

bool linear_search(int arr[5], int num, int size) {
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == num){
            return true;
        }
    }
    return false;
}

int main(){

    int num;
    int arr[] = { 2 ,4 ,1, 6, 3 };
    int size = sizeof(arr)/sizeof(arr[0]);
    cin >> num;
    if(linear_search(arr,num,size)){
        cout << "Present";
    }else{
        cout << "Absent";
    }
}


