#include<iostream>
using namespace std;
#include<climits>
//recursion
int countWaysToMakeChange(int coins[], int m, int value){
    if(value==0){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=0;i<m;i++){
        if(coins[i]<=value){
            int x=1+countWaysToMakeChange(coins,m,value-coins[i]);
            if(x < ans && x!=INT_MAX){
                ans=x;
            }
        }
    }
    return ans;
}
//dp
int mincount(int coins[],int m, int v){
	int*dp=new int[v+1];
	dp[0]=0;
	for(int i=1;i<=v;i++){
		dp[i]=INT_MAX;
	}
	for(int i=1;i<=v;i++){
		for(int j=0;j<m;j++){
			if(coins[j]<=i){
				int x=dp[i-coins[j]];
				if(x!=INT_MAX && x+1<dp[i]){
					dp[i]=x+1;
				}
			}
		}
	}
	return dp[v];
}
int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value)<<endl;
  cout << mincount(denominations, numDenominations, value)<<endl;

}



