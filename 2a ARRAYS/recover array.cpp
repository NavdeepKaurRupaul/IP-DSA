#include<iostream>
using namespace std;
void recoverArray(int input[],int n,int output[]){
	int left,right;
	int i=0;
	int mid=n/2;
	if(n%2!=0){
		output[mid]=input[i];
		i++;
		left=mid-1;
		right=mid+1;
	}
	else{
		left=mid-1;
		right=mid;
	}
	while(i<n){
		output[left]=input[i];
		i++;
		left--;
		output[right]=input[i];
		i++;
		right++;
	}
}
int main(){
	int n;
	cin>>n;
	int * a=new int(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int *b= new int(n);
	recoverArray(a,n,b);
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
