#include<iostream>
using namespace std;
void merge(int arr1[], int size1, int arr2[], int size2, int ans[]){
	int i=0,j=0,c=0;
	while(i<size1 && j<size2){
		if(arr1[i]<arr2[j]){
			ans[c]=arr1[i];
			i++;
			c++;
		}
		else if(arr1[i]>arr2[j]){                  
			ans[c]=arr2[j];
			c++;
			j++;
		}
		else if(arr1[i]==arr2[j]){
			ans[c]=arr1[i];
			c++;
			i++;
			ans[c]=arr2[j];
			c++;
			j++;
		}
	}
		while(j<size2){
			ans[c]=arr2[j];
			c++;
			j++;
		}
		while(i<size1){
			ans[c]=arr1[i];
			i++;
			c++;
		}
}
int main(){
  int size1;  
  cin >> size1;
  int* arr1 = new int[size1];
  for(int i = 0; i < size1; i++){
    cin >> arr1[i];
  } 
  int size2;  
  cin >> size2;
  int* arr2 = new int[size2];
  for(int i = 0; i < size2; i++){
    cin >> arr2[i];
  } 
  int* ans = new int[size1 + size2];
  merge(arr1, size1, arr2, size2, ans);
  for(int i = 0; i < size1 + size2; i++){
			cout << ans[i] <<  " ";
		}
  delete arr1;
  delete arr2;
  delete ans;
}



