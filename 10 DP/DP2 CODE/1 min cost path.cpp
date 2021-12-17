#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//recursion
int minCostPath(int **input, int m, int n, int i, int j) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}
	if(i >= m || j >= n) {
		return INT_MAX;
	}

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1);
	int y = minCostPath(input, m, n, i+1, j+1);
	int z = minCostPath(input, m, n, i+1, j);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
	return ans;
}
int minCostPath(int **input, int m, int n) {
	return minCostPath(input, m, n, 0, 0);
}
//memoization
int helper(int ** input,int m,int n,int i,int j,int**dp){
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}
	if(i >= m || j >= n) {
		return INT_MAX;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int x = minCostPath(input, m, n, i, j+1);
	int y = minCostPath(input, m, n, i+1, j+1);
	int z = minCostPath(input, m, n, i+1, j);
	dp[i][j] = min(x, min(y, z)) + input[i][j];
	return dp[i][j];	
}
int mincostpathmemo(int **input,int m,int n){
	int ** dp=new int*[m];
	for(int i=0;i<m;i++){
		dp[i]=new int[n];
		for(int j=0;j<n;j++){
			dp[i][j]=-1;
		}
	}
	return helper(input,m,n,0,0,dp);
}
//dp
int mincostpathdp(int **input,int m,int n){
	int ** dp=new int*[m];
	for(int i=0;i<m;i++){
		dp[i]=new int[n];
	}
	dp[m-1][n-1]=input[m-1][n-1];
	for(int i=m-2;i>=0;i--){
		dp[i][n-1]=input[i][n-1]+dp[i+1][n-1];
	}
	for(int i=n-2;i>=0;i--){
		dp[m-1][i]=input[m-1][i]+dp[m-1][i+1];
	}
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			dp[i][j]=min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]))+input[i][j];
		}
	}
	return dp[0][0];
}
int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
    cout << mincostpathmemo(arr, n, m) << endl;
    cout << mincostpathdp(arr, n, m) << endl;
}

