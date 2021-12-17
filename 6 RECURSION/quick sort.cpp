#include<iostream>
using namespace std;
void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int start, int end) { 
    int pivot = arr[end];
    int i = (start - 1);  
    for (int j = start; j <= end- 1; j++) {
        if (arr[j] <= pivot) { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[end]); 
    return (i + 1); 
}
void quicksort(int input[],int start,int end){
	if(start>=end){
		return;
	}
	int pi = partition(input, start, end);
        quicksort(input, start, pi - 1);
        quicksort(input, pi + 1, end);
}
void quickSort(int input[], int size) {
	int start=0;
	int end=size-1;
	quicksort(input,start,end);
}
int main(){
    int n;
    cin >> n; 
    int *input = new int[n];   
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }   
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }   
    delete [] input;
}



