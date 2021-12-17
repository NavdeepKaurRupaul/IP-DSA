#include<iostream>
#include<climits>
using namespace std;
void Leaders(int* arr,int len){
    for (int i = 0; i < len; i++) { 
        int j; 
        for (j = i+1; j < len; j++) { 
            if (arr[i] < arr[j]) {
            	break; 
			}      
        }     
        if (j == len) // the loop didn't break 
            cout << arr[i] << " "; 
  } 
}

int main(){
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}

