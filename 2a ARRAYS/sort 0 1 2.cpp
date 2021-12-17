#include <iostream>
#include <algorithm>
using namespace std;
void sort012(int arr[], int n)  {
	int one=0;
	int zero=0;
	int two=0;
	for(int i=0;i<n;i++){
		if(arr[i]==1){
			one++;
		}
		else if(arr[i]==2){
			two++;
		}
		else{
			zero++;
		}
	}
	int i=0;
	while(i<n){
		while(zero>0){
			arr[i]=0;
			zero--;
			i++;
		}
		while(one>0){
			arr[i]=1;
			one--;
			i++;
		}
		while(two>0){
			arr[i]=2;
			two--;
			i++;
		}
	}
}

int main() {

	int size_first;

	cin>>size_first;
	int *arr_first=new int[1+size_first];	
	
	for(int i=0;i<size_first;i++)
		cin>>arr_first[i];
	
	sort012(arr_first,size_first);
		
	for(int i=0;i<size_first;i++)
		cout<<arr_first[i]<<" ";	
	return 0;
}

