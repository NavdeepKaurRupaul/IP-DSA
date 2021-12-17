#include<iostream>
#include<algorithm>
using namespace std;
int platformsNeeded(int arrival[], int departure[], int n) { 
   sort(arrival, arrival+n); 
   sort(departure, departure+n); 
   int plat_needed = 1, result = 1; 
   int i = 1, j = 0; 
   while (i < n && j < n) {
      if (arrival[i] <= departure[j]) { 
          plat_needed++; 
          i++;
          if (plat_needed > result) {
          	result = plat_needed; 
		  }          
      } 
      else{ 
          plat_needed--; 
          j++; 
      } 
   } 
  
   return result; 
} 
  
int main(){
	int n;
	cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++) {
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++){
    	cin>>dep[i];
	}
    cout<< platformsNeeded(arr, dep, n);
}

