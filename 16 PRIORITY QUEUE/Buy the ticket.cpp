#include <iostream>
#include <vector>
using namespace std;
#include<queue>
int buyTicket (int *input, int n, int k){
    queue<int> q;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
    	q.push(input[i]);
    	pq.push(input[i]);
	}
    int count=0;
    while(!pq.empty()){
    	if(q.front()==pq.top()){
    		if(k==0){
    			return count+1;
			}
			else{
				count++;
				q.pop();
				pq.pop();
				k--;
			}
		}
		else{
			q.push(q.front());
			q.pop();
			if(k==0){
				k=q.size()-1;
			}
			else{
				k--;
			}
		}
	}
	return count;
}

int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}

