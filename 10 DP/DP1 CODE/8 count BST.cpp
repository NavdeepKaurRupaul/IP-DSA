#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int mod=1000000007;
int countBST(int n){
	if(n<0){
		return 0;
	}
	if(n==1 || n==0){
		return 1;
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		int temp1=countBST(n-1)%mod;
		int temp2=countBST(n-2)%mod;
		ans+=(temp1+temp2);
	}
	return ans-1;
}
//dp
int countBSTdp( int n)
{
  long long dp[n + 1]; 
    fill_n(dp, n + 1, 0); 
    dp[0] = 1; 
    dp[1] = 1; 
    for (int i = 2; i <= n; i++) { 
        for (int j = 1; j <= i; j++) { 
            dp[i] = (dp[i] +( (dp[i - j] * dp[j - 1]))%mod)%mod; 
        } 
    } 
    return dp[n]; 
} 
int main(){
	int n ;
	cin>>n;
	cout<<countBSTdp(n);
	return 0;
}

