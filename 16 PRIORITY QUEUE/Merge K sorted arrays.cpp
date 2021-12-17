#include <iostream>
using namespace std;
#include <vector>
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    vector<int> v;
    priority_queue<int, vector<int>, greater<int> >q;
    for(int i=0;i<input.size();i++){
    	for(int j=0;j<input[i]->size();j++){
    		q.push(input[i]->at(j));
		}
	}
	while(!q.empty()){
		v.push_back(q.top());
		q.pop();
	}
	return v;

}

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}

