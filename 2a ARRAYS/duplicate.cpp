#include <iostream>
using namespace std;
int MissingNumber(int arr[], int size){
	for(int i=0;i<size;i++){;
		for(int j=i+1;j<size;j++){
			if(arr[i]==arr[j]){
				return arr[i];
				break;
			}
		}
	}
}

int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];	
	for(int i = 0; i < size; i++)
		cin >> input[i];	
	cout << MissingNumber(input, size);		
	delete [] input;
	return 0;
}

