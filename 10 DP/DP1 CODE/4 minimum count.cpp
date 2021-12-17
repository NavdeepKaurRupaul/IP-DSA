#include <bits/stdc++.h>
#include<cmath>
using namespace std;
//recursion;
int minCount(int n){
	if(n==0){
		return 0;
	}
	int x=INT_MAX;
	int min=INT_MAX;
	for(int i=1;i<=sqrt(n);i++){
		x=minCount(n-i*i);
		if(x<min){
			min=x;
		}
	}
	return 1+min;
}
//memoization
int helper(int n,int*a){
	if(n==0){
		return 0;
	}
	if(a[n]!=-1){
		return a[n];
	}
	int x=INT_MAX;
	int min=INT_MAX;
	for(int i=1;i<=sqrt(n);i++){
		x=helper(n-i*i,a);
		if(min>x){
			min=x;
		}
	}
	a[n]=1+min;
	return a[n];
}
int minCountmemo(int n){
	int *a=new int[n+1];
	for(int i=0;i<=n;i++){
		a[i]=-1;
	}
	return helper(n,a);
}
//dp
int minCountDP(int n){
	int*a=new int[n+1];
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=INT_MAX;
		for(int j=1;j<=sqrt(n);j++){
			a[i]=min(a[i],a[i-(j*j)]);
		}
		a[i]+=1;
	}
	return a[n];
}
int main(){
	int n;
	cin >> n;
	cout << minCountDP(n);9
}

