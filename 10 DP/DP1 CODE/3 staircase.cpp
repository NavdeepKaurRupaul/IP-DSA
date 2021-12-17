#include <iostream>
using namespace std;
//recursion
long staircase(int n){
	if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int x=staircase(n-1);
    int y=staircase(n-2);
    int z=staircase(n-3);
    return x+y+z;
}
//memoization
int helper(int n,int *a){
	if(n<=1){
		return 1;
	}
    if(n==2){
        return 2;
    }
	if(a[n]!=-1){
		return a[n];
	}
    long a1=helper(n-1,a);
    long a2=helper(n-2,a);
    long a3=helper(n-3,a);
	a[n]=a1+a2+a3;
	return a[n];
}
int staircasememo(int n){
	int * a=new int[n+1];
	for(int i=0;i<=n;i++){
		a[i]=-1;
	}
	return helper(n,a);
}
//dp
long staircasedp(int n){
	long * a=new long[n+1];
	a[0]=1;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	return a[n];
}
int main(){
	int n;
	cin >> n;
	cout << staircasedp(n);
}

