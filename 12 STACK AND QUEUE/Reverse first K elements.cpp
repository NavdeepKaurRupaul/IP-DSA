#include <cmath>
#include <iostream>
using namespace std;
#include <cmath>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std;
#include<queue>
#include<stack>
queue<int> reverseKElements(queue<int> input, int k) {
	stack<int> s1;
	stack<int> s2;
    int n=input.size();
	while(! input.empty()){
		s1.push(input.front());
		input.pop();
	}
	for(int i=0;i<n-k;i++){
		s2.push(s1.top());
		s1.pop();
	}
	while(! s1.empty()){
		input.push(s1.top());
		s1.pop();
	}
	while(! s2.empty()){
		input.push(s2.top());
		s2.pop();
	}
	return input;
}


int main() {
	int n=0;
	cin>>n;
	queue<int> Queue;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		Queue.push(temp);
	}
	int k;
	cin>>k;
	
	queue<int> ans = reverseKElements(Queue,k);
	while (!ans.empty()) {
        	cout << ans.front() << endl;
        	ans.pop();
    	}
}

