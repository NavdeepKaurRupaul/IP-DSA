#include<iostream>
using namespace std;
#include<unordered_map>
void printPairs(int arr[], int n, int sum) { 
    // Store counts of all elements in map m 
    unordered_map<int, int> m; 
    // Traverse through all elements 
    for (int i = 0; i < n; i++) { 
        // Search if a pair can be formed with arr[i]. 
        int rem = sum - arr[i]; 
        if (m.find(rem) != m.end()) { 
            int count = m[rem]; 
            for (int j = 0; j < count; j++) {
            	if(rem<arr[i]){
            		cout << rem <<" " <<arr[i] << endl;
				}
            	 else{
            	 	cout <<arr[i]<<" " << rem<< endl;
				 }
			}     
        } 
        m[arr[i]]++; 
    } 
}
void PairSum(int *input, int n) {	 
    printPairs(input, n,0);	
}	
int main(){
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}

