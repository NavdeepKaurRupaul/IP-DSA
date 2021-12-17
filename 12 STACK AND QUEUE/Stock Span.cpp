#include <iostream>
using namespace std;
#include <stack>
int* stockSpan(int *price, int size) {
	stack<int> s;
	s.push(1);
	for(int i=1;i<size;i++){
		int span=1;
		for(int j=i-1;j<=0;j--){
			if(price[j]<price[i]){
				span++;
			}
		}
		s.push(span);
	}
	 stack<int>ans;
	while(!s.empty()){
		ans.push(s.top());
		s.pop();
	}
	int i=0;
	while(!ans.empty()){
		price[i]=ans.top();
		ans.pop();
	}
	return price;
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}

