#include<iostream>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight){
	if(n==0){
		return 0;
	}
	if(maxWeight<=0){
		return 0;
	}
	if(maxWeight<weights[0]){
		return knapsack(weights+1,values+1,n-1,maxWeight);
	}
	int added=values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
	int notadded=knapsack(weights+1,values+1,n-1,maxWeight);
	int ans=max(added,notadded);
	return ans;
}
//memoization
int helper(int* w, int* v, int n, int mw,int **dp){
	if(n==0){
		return 0;
	}
	if(mw<=0){
		return 0;
	}
	if(dp[n][mw]!=-1){
		return dp[n][mw];
	}
	if(mw<w[0]){
		dp[n][mw]=helper(w+1,v+1,n-1,mw,dp);
		return dp[n][mw];
	}
	int added=v[0]+helper(w+1,v+1,n-1,mw-w[0],dp);
	int notadded=helper(w+1,v+1,n-1,mw,dp);
	int ans=max(added,notadded);
	dp[n][mw]=ans;
	return dp[n][mw];
}

int knapsackmemo(int* weights, int* values, int n, int maxWeight){
	int **dp=new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i]=new int[maxWeight+1];
		for(int j=0;j<=maxWeight;j++){
			dp[i][j]=-1;
		}
	}
	return helper(weights,values,n,maxWeight,dp);
}
int main() {
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsackmemo(weights, values, n, maxWeight) << endl;
}
