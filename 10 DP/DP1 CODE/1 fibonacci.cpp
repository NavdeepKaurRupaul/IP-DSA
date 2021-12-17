#include<iostream>
using namespace std;
//recursive
int fib(int n){
	if(n<=1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}
//memoization
int fibM(int n,int *a){
	if(n<=1){
		return n;
	}
	if(a[n]!=-1){
		return a[n];
	}
	int output=fibM(n-1,a)+fibM(n-2,a);
	a[n]=output;
	return a[n];
}
int fibm(int n){
	int * a=new int[n+1];
	for(int i=0;i<=n;i++){
		a[i]=-1;
	}
	return fibM(n,a);
}
//dp
int fibDP(int n){
	int *a=new int[n+1];
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=a[i-2]+a[i-1];
	}
	return a[n];
}
int main(){
	int n;
	cin>>n;
	cout<<fibDP(n)<<endl;
}
