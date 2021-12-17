#include <iostream>
using namespace std;
#include<queue>
#include<cmath>
using namespace std;
void findMedian(int arr[], int n){
  cout << arr[0] << endl;
  int median;
  if(n<1){
    return;
  }
  priority_queue<int, vector<int>, greater<int> > min;
  priority_queue<int> max;
  
  if(arr[1] > arr[0]){
    min.push(arr[1]);
    max.push(arr[0]);
  }
  else{
    min.push(arr[0]);
    max.push(arr[1]);
  }
  cout << (arr[1] + arr[0])/2 << endl;
  
  for(int i=2; i<n; i++){
    if(arr[i] < max.top()){
      max.push(arr[i]);
    }
    else{
      min.push(arr[i]);
    }
    if(abs(max.size()-min.size()) > 1){
      if(max.size() > min.size()){
        min.push(max.top());
        max.pop();
      }
      else{
        max.push(min.top());
        min.pop();
      }
    }
    if(max.size() == min.size()){
      cout << (max.top() + min.top())/2 << endl;
    }
    else if(max.size() > min.size()){
      cout << max.top() << endl;
    }
    else{
      cout << min.top() << endl;
    }
  }

}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    
}

