#include<iostream>
using namespace std;
#include<queue>
void KSortedArray(int a[],int n,int k){
	priority_queue<int> pq;
	for(int i=0;i<k;i++){
		pq.push(a[i]);
	}
	int j=0;
	for(int i=k;i<n;i++){
		a[j]=pq.top();
		pq.pop();
		pq.push(a[i]);
		j++;
	}
	while(!pq.empty()){
		a[j]=pq.top();
		pq.pop();
		j++;
	}
}
int main(){
	int a[]={10,12,6,7,4};
	int k=3;
	KSortedArray(a,5,k);
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}	
	cout<<endl;
}
