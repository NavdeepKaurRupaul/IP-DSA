#include <cmath>
#include <iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
int minDistance(int arr[],int n){
	unordered_map<int,int> m;
	vector<int>v;
	int diff=0;
	for(int i=0;i<n;i++){
		if(m.count(arr[i])>0){
			int a= max(m[arr[i]],i);
			int b= min(m[arr[i]],i);
			int c=a-b;
			v.push_back(c);
		}
		else{
			m[arr[i]]=i;
		}
	}
	int min=INT_MAX;
	for(int i=0;i<v.size();i++){
		if(min>v[i]){
			min=v[i];
		}
	}
	v.clear();
	return min;
}

int main() {
    	int n=0;
    	cin>>n;
    	int *arr = new int[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	cout << minDistance(arr,n);
}

