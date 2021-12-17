#include<iostream>
#include<unordered_map>
using namespace std;
bool subArrayZeroSum(int input[], int n) {
	unordered_map<int,int> m;  
    // Traverse through array and store prefix sums 
    int sum = 0; 
    for (int i = 0 ; i < n ; i++) { 
        sum =sum+ input[i]; 
        // If prefix sum is 0 or it is already present 
        if (sum == 0 || m.find(sum) != m.end()){
        	return true;
		}  
        m[sum]=sum; 
    } 
    return false; 	
}


int main(){
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }
    bool val = subArrayZeroSum(input, n);
    if(val){
        cout<<"true";
    }
    else {
            cout<<"false";
    }
    return 0;
}


