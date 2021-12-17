#include<iostream>
using namespace std;
#include <unordered_map>
#include<vector>
vector <int> longestConsecutiveIncreasingSequence(int *arr, int n){
	unordered_map <int, bool> visitedelements;
	unordered_map <int, bool> elementstoindexmapping;
	for(int i=0;i<n;i++){
		elementstoindexmapping[arr[i]]=i;
		if(visitedelements.count(arr[i])==0){
			visitedelements[arr[i]]=true;
		}
	}
	vector<int> longestsequence;
	int globalmaxsequencelenght=1;
	int globalminstartindex=0;
	for(int i=0;i<n;i++){
		int num=arr[i];
		int currentminstartindex=i;
		int count=0;
		int tempnum=num;
		while(visitedelements.count(tempnum)==1 && visitedelements[tempnum]==true){
			visitedelements[tempnum]=false;
			count++;
			tempnum++;
		}
		tempnum=num-1;
		while(visitedelements.count(tempnum)==1 && visitedelements[tempnum]==true){
			visitedelements[tempnum]=false;
			count++;
			currentminstartindex= elementstoindexmapping[tempnum];
			tempnum--;
		}
		if(count>globalmaxsequencelenght){
			globalmaxsequencelenght=count;
			globalminstartindex=currentminstartindex;
		}
		else if (count==globalmaxsequencelenght){
			if(currentminstartindex<globalminstartindex){
				globalminstartindex=currentminstartindex;
			}
		}
	}
	int globalstartnum=arr[globalminstartindex];
	longestsequence.push_back(globalstartnum);
	globalmaxsequencelenght--;
	while(globalmaxsequencelenght!=0){
		globalstartnum++;
		longestsequence.push_back(globalstartnum);
	    globalmaxsequencelenght--;
	}
	return longestsequence;
}
int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }
  delete arr;
}
