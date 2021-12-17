#include<iostream>
#include<cmath>
#include<unordered_map>
using namespace std;
void printPairs(int *arr, int n, int k) {
	unordered_map<int, int> m;
	for(int i=0;i<n;i++){
		m[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		int key1=arr[i];
		int key2=key1-k;
        int key3=key1+k;
		if(key1 != key3 && key1 != key2){
			int count1= m[key1]*m[key2];
			while(count1!=0){
				cout<<min(key1,key2)<<" "<<max(key1,key2)<<endl;
				count1--;
			}
            int count2 = m[key1]*m[key3];
			while(count2!=0){
				cout<<min(key1,key3)<<" "<<max(key1,key3)<<endl;
				count2--;
			}
			m[key1]=0;
			//m[key2]=0;
		}
		if(key1 == key2 &&key1==key3 && m[key1]>1){
			int keycount=m[key1];
			int count1=1;
			int count2=keycount-1;
			int c=count1*count2;
			while(c!=0){
				c=count1*count2;
				int a=count2;
				while(a!=0){
					cout<<key1<<" "<<key1<<endl;
				    a--;
				}
				count2--;				
			}
			m[key1]=0;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}

