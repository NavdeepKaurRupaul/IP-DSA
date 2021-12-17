#include<iostream>
using namespace std;
int fact(int n){
	if(n==1){
		return 1;
	}
	int smalloutput=fact(n-1);
	return n*smalloutput;
}
int main(){
	int n;
	cin>>n;
	int ans=fact(n);
	cout<<ans<<endl;
}
