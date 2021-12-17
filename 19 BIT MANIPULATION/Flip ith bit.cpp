#include<iostream>
using namespace std;
int flip(int n,int i){
	int z=n^(1<<i);
	return z;
}
int main(){
	int n,i;
	cin>>n>>i;
	cout<<flip(n,i)<<endl;
}
