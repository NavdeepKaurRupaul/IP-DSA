#include <iostream>
using namespace std;
bool checkMaxHeap(int arr[], int n){
    int CI=1;
    int PI=(CI-1)/2;
    while(CI<n){
    	if(arr[PI]<arr[CI]){
    		return false;
		}
		CI++;
		PI=(CI-1)/2;
	}
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}

