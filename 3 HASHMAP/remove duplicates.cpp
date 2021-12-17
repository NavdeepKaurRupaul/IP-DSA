#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> removeduplicates(int a[], int n){
	vector<int> output;
	unordered_map <int, bool> seen;
	for(int i=0;i<n;i++){
		if(seen.count(a[i])>0){
			continue;
		}
		//else{
			seen[a[i]]=true;
			output.push_back(a[i]);
		//}
	}
	return output;
}
int main(){
	int a[]={1,2,3,2,3,4,5,6,3,4};
	vector<int> output=removeduplicates(a,10);
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
}
