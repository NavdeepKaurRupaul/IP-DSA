#include<iostream>
using namespace std;
#include <unordered_map>
#include<vector>
vector <int> longestSubsequence(int *arr, int n){
	unordered_map <int, bool>m ;
	for(int i=0;i<n;i++){
		if(m.count(arr[i])==0){
			m[arr[i]]=true;
		}
	}
	int maxcount =1;
	int start =arr[0];
	vector<int> output;
	for(int i=0;i<n;i++){
		int count=0;
		int temp=arr[i];
		while(m.count(temp)!=0){
			count++;
			temp++;
		}
		if(maxcount<count){
			maxcount=count;
			start=arr[i];
		}
	}
	while(maxcount!=0){
		output.push_back(start);
		start++;
		maxcount--;
	}
	return output;
}
int main(){
  int size;
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestSubsequence(arr,size);
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }
  delete arr;
}
