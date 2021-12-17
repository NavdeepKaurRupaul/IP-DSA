#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int n1=(n+1)/2;
	int n2=n/2;
	for(int i=1;i<=n1;i++){
		for(int k=1;k<=i-1;k++){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"* ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n2;i++){
		for(int k=1;k<=n2-i;k++){
			cout<<" ";
		}
		for(int j=n2-i+1;j>0;j--){cout<<"* ";
		}
		cout<<endl;
	}
}



