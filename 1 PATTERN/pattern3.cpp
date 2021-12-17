#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<=i;j++){
			cout<<j;
		}
	for(int k=i+1;k<=2*n-i;k++){
		cout<<" ";
	}
	int k=i;
	for(int l=1;l<=i;l++){
		cout<<k;
		k--;
	}
	cout<<endl;
  } 
}	


