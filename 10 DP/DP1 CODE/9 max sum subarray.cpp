#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include<climits>
int findSum(int arr[],int n){
    int * output = new  int[n];
    output[0]=arr[0];
    for(int i=1;i<n;i++){
       /* output[i]=arr[i];
        if(arr[i-1] > 0 && i >= 0){
            output[i]+=output[i-1];
        }*/
        if(arr[i]  + output[i-1] > arr[i]){
            output[i]= arr[i] +output[i-1];
        }
        else{
            output[i]=arr[i];
        }
            
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max < output[i]){
            max=output[i];
        }
    }
    delete [] output;
    return max;
} 
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
	cout<<findSum(arr,n);

    return 0;
}

