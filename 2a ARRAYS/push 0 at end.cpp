#include <iostream>
#include<climits>
using namespace std;
void PushZeroesEnd(int A[], int n){
	int k = 0;
	for (int i = 0; i < n; i++){
		if (A[i] != 0){
			A[k] = A[i];
			k++;
		}		
	}
	for (int i = k; i < n; i++)
		A[i] = 0;
}

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	PushZeroesEnd(input,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	
	return 0;

}

