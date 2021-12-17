#include<iostream>
using namespace std;
void printPattern(int n){
	
	for(int i=1;i<=n;i++){
		int k=n;
		for(int j=1;j<=i;j++){
			cout<<k<<" ";
			k--;
		}
		int a=n-i+1;
		for(int l=1;l<=n-i;l++){
			cout<<a<<" ";
		}
		for(int m=1;m<=n-i;m++){
			cout<<a<<" ";
		}
		int b=n-i+2;
		for(int o=1;o<i;o++){
			cout<<b<<" ";
			b++;
		}
		cout<<endl;
	}
	for(int i=1;i<=n-1;i++){
		int a=n;
		for(int j=n-i;j>0;j--){
			cout<<a<<" ";
			a--;
		}
		for(int k=1;k<=i;k++){
			cout<<i+1<<" ";
		}
		for(int m=1;m<=i;m++){
			cout<<i+1<<" ";
		}
		int b=i+2;
		for(int l=n-1;l>i;l--){
			cout<<b<<" ";
			b++;
		}
		cout<<endl;
	}
}
int main(){
  int n;
  cin >> n;
  printPattern(n);
}



