#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n-i;k++){
			cout<<" ";
		}
		k=i;
		for(int j=1;j<=i;j++){
			cout<<k;
			k++;
		}
		for(int l=i-1;l>=1;l--){
		cout<<l+i-1;
	}
		cout<<endl;
	}
}
