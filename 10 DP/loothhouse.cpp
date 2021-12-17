#include<iostream>
using namespace std;
#include<algorithm>
int getMaxMoney(int arr[],int n){
	int * dp=new int[n];
	dp[0]=arr[0];
	if(n>1){
		dp[1]=max(arr[1],dp[0]);
	}
	for(int i=2;i<n;i++){
		dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
	}
	return dp[n-1];
}
int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}


