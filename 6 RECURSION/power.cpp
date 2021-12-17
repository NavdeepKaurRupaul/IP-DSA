#include<iostream>
using namespace std;
int power(int x,int n){
	if(n==0){
		return 1;
	}
	int smalloutput=power(x,n-1);
	return x*smalloutput;
}
int main(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	int ans=power(x,n);
	cout<<ans<<endl;
}
