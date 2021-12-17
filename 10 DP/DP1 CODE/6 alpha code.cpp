#include <bits/stdc++.h>
using namespace std;
//recursion
int count(int *a,int n){
	if(n<=1){
		return 1;
	}
	int output=count(a,n-1);
	if(a[n-2]*10 + a[n-1] <= 26){
		output+=count(a,n-2);
	}
	return output;
}
//memomisation
int helper(int *a,int n,int *ans){
	if(n<=1){
		return 1;
	}
	if(ans[n]!=-1){
		return ans[n];
	}
	ans[n]=helper(a,n-1,ans);
	if(a[n-2]*10+a[n-1]<=26){
		ans[n]+=helper(a,n-2,ans);
	}
	return ans[n];
}
int countMemo(int *a,int n){
	int *ans=new int[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=-1;
	}
	return helper(a,n,ans);
}
//dp
int countDP(int *a,int n){
	int*ans=new int[n+1];
	ans[0]=1;
	ans[1]=1;
	for(int i=2;i<=n;i++){
		ans[i]=ans[i-1];
		if(a[i-2]*10 + a[i-2] <=26){
			ans[i]+=ans[i-2];
		}
	}
	return ans[n];
}
int main(){
	int n;
	cin>>n;
	int * a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<countDP(a,n);
    return 0;
}

