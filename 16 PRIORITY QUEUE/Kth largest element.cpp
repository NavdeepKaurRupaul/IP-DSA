#include <iostream>
#include <vector>
using namespace std;
#include<queue>
int kthLargest (vector<int> arr, int n, int k){
    priority_queue<int >p;
    for(int i=0;i<n;i++){
    	p.push(arr[i]);
	}
	int count=1;
	while(!p.empty()){
		//cout<<p.top()<<" ";
		int ans=p.top();
		p.pop();
		if(count==k){
			return ans;
		}
		count++;
	}
	
	//return arr[k];
}

int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}

