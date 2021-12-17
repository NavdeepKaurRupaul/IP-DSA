#include<iostream>
using namespace std;
int fib(int n , int* arr){
	if(n==0 || n==1){
		return 1;
	}
	if(arr[n]>0){
		return arr[n];
	}
	int output=fib(n-1,arr)+fib(n-2,arr);
	arr[n]=output;
	return output;
}
int main(){
	int n;
	cin>>n;
	int * arr=new int(n+1);
	for(int i=0;i<n+1;i++){
		arr[i]=0;
	}
	cout<<fib(n,arr);
}
