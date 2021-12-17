#include<unordered_map>
#include <cmath>
#include <iostream>
using namespace std;
/*We can use map to solve this problem in linear time. 
The idea is to replace O with -1 and find out the largest subarray with O sum. 
To find largest subarray with O sum, we create an empty map which stores the ending index of first sub array having given sum. 
We traverse the given array, and maintain sum of elements seen so far. 
If sum is seen for first time, insert the sum with its index into the map. 
If sum is seen before, there exists a sub-array ith O sum which ends at current index and we update maximum length sub-array 
if current sub-array has more length.*/
int countSubarrWithEqualZeroAndOne(int arr[], int n) { 
     // create an empty map to store ending index of first sub-array having some sum
	unordered_map<int, int> map;
	// insert (0, -1) pair into the set to handle the case when sub-array with sum 0 starts from index 0
	map[0] = -1;
	// len stores the maximum length of sub-array with sum 0
	int len = 0;
	// stores ending index of maximum length sub-array having sum 0
	int ending_index = -1;
	int sum = 0;
	// Traverse through the given array
	for (int i = 0; i < n; i++){
		// sum of elements so far (replace 0 with -1)
		sum += (arr[i] == 0)? -1 : 1;
		// if sum is seen before
		if (map.find(sum) != map.end()){
			// update length and ending index of maximum length sub-array having sum 0
			if (len < i - map[sum]){
				len = i - map[sum];
				ending_index = i;
			}
		}
		// if sum is seen for first time, insert sum with its index into the map
		else {
			map[sum] = i;
		}
	}
	int count=0;
	for(int i=ending_index-len+1;i<=ending_index;i++){
		count++;
	}
	return count;
}
int main() {
    	int n=0;
    	cin>>n;
    	int *arr = new int[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
       cout<<countSubarrWithEqualZeroAndOne(arr,n);
}

