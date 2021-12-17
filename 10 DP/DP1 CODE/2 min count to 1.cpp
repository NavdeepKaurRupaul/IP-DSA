#include <bits/stdc++.h>
#include<climits>
using namespace std;
//recurssion
int countStepsToOne(int n){
	if(n==1){
		return 0;
	}
	int ans=1;
	if(n>1){
		int sub1=countStepsToOne(n-1);
		int div2=INT_MAX;
		int div3=INT_MAX;
		if(n%2==0){
			div2=countStepsToOne(n/2);
		}
		if(n%3==0){
			div3=countStepsToOne(n/3);
		}
		ans+=min(sub1,min(div2,div3));
	}
	return ans;
}
//memoization
int helper(int n,int *a){
	if(n==1){
		return 0;
	}
	if(a[n]!=-1){
		return a[n];
	}
	int sub1=helper(n-1,a);
	int div2=INT_MAX;
	int div3=INT_MAX;
	if(n%2==0){
		div2=helper(n/2,a);
	}
	if(n%3==0){
		div3=helper(n/3,a);
	}
	a[n]=1+min(sub1,min(div2,div3));
	return a[n];
}
int countStepsToOneMemo(int n){
	int *a=new int[n+1];
	for(int i=0;i<=n;i++){
		a[i]=-1;
	}	
	return helper(n,a);
}
//dp
int countStepsToOneDP(int n){
	int * a=new int[n+1];
	a[0]=0;
	a[1]=0;
	a[2]=1;
	a[3]=1;
	for(int i=4;i<=n;i++){
		int sub1=a[i-1];
		int div2=INT_MAX;
		if(i%2==0){
			div2=a[i/2];
		}
		int div3=INT_MAX;
		if(i%3==0){
			div3=a[i/3];
		}
		a[i]=1+min(sub1,min(div2,div3));
	}
	return a[n];
}

int main(){
	int n;
	cin >> n;
	cout << countStepsToOneDP(n);
}

